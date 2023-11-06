// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Charachter/Player/AuraPlayerAttributeSet.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
    PrimaryActorTick.bCanEverTick = false;

     SphereVolume = CreateDefaultSubobject<USphereComponent>("Sphere");
     StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
     SetRootComponent(SphereVolume);
     StaticMesh->SetupAttachment(SphereVolume);
}

void AAuraEffectActor::OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                 const FHitResult& SweepResult)
{
    if (IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
    {
        const UAuraPlayerAttributeSet* AuraPlayerAttributeSet = Cast<UAuraPlayerAttributeSet>(
            AbilitySystemInterface->GetAbilitySystemComponent()->
                                    GetAttributeSet(UAuraPlayerAttributeSet::StaticClass()));
        UAuraPlayerAttributeSet* MutableAuraPlayerAttributeSet = const_cast<UAuraPlayerAttributeSet*>(
            AuraPlayerAttributeSet);
        MutableAuraPlayerAttributeSet->SetMaxHealth(100);
    }

    Destroy();
}

void AAuraEffectActor::OnEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AAuraEffectActor::BeginPlay()
{
    Super::BeginPlay();
    SphereVolume->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverLap);
    SphereVolume->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::OnEndOverLap);
}

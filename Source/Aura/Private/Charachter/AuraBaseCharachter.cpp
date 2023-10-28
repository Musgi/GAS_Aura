// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/AuraBaseCharachter.h"

AAuraBaseCharachter::AAuraBaseCharachter()
{
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraBaseCharachter::BeginPlay()
{
	Super::BeginPlay();
}

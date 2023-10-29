// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/Enemy/AuraEnemyBaseCharachter.h"

#include "Aura/Aura.h"
#include "Charachter/Enemy/AuraEnemyAbilitySystemComponent.h"
#include "Charachter/Enemy/AuraEnemyAttributeSet.h"

AAuraEnemyBaseCharachter::AAuraEnemyBaseCharachter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraEnemyAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UAuraEnemyAttributeSet>("AtttributeSet");
}

void AAuraEnemyBaseCharachter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAuraEnemyBaseCharachter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	WeaponMesh->SetRenderCustomDepth(true);
	WeaponMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemyBaseCharachter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	WeaponMesh->SetRenderCustomDepth(false);
}

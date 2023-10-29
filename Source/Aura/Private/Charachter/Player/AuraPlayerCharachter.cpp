// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/Player/AuraPlayerCharachter.h"

#include "Charachter/Player/AuraPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraPlayerCharachter::AAuraPlayerCharachter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 300, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraPlayerCharachter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilitySystemActorInfo();
}

void AAuraPlayerCharachter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilitySystemActorInfo();
}

void AAuraPlayerCharachter::InitAbilitySystemActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = CastChecked<UAuraPlayerAbilitySystemComponent>(
		AuraPlayerState->GetAbilitySystemComponent());
	AttributeSet = CastChecked<UAuraPlayerAttributeSet>(AuraPlayerState->GetAttributeSet());
}

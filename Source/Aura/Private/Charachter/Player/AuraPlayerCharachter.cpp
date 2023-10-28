// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/Player/AuraPlayerCharachter.h"

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

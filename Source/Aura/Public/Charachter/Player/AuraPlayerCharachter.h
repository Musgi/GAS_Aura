// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Charachter/AuraBaseCharachter.h"
#include "AuraPlayerCharachter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerCharachter : public AAuraBaseCharachter
{
	GENERATED_BODY()
public:
	AAuraPlayerCharachter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilitySystemActorInfo();
};


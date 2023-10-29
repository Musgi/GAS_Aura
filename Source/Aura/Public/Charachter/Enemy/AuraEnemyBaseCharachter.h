// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Charachter/AuraBaseCharachter.h"
#include "Interfaces/Interaction.h"
#include "AuraEnemyBaseCharachter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemyBaseCharachter : public AAuraBaseCharachter, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemyBaseCharachter();
	void HighlightActor() override;
	void UnHighlightActor() override;
protected:
	virtual void BeginPlay() override;
};

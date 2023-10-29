// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSetBase.generated.h"


/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttribute MaxHealth;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttribute& OldMaxHealth) const;
};

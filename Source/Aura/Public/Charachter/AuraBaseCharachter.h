// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraBaseCharachter.generated.h"

UCLASS(Abstract)
class AURA_API AAuraBaseCharachter : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraBaseCharachter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
};

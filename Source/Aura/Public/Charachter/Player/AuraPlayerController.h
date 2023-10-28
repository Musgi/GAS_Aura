// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


/**
 * 
 */
class UInputMappingContext;
class UInputAction;
class IInteractionInterface;
struct FInputActionValue;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> AuraDefaultInputMappingContext;
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveInputAction;
	
	TObjectPtr<IInteractionInterface> CurrentActorUnderCursor;
	TObjectPtr<IInteractionInterface> PreviousActorUnderCursor;
	
	void Move(const FInputActionValue& InputActionValue);
	void CheckActorUnderMouseCursor();
	void HandelHighlighting();
};

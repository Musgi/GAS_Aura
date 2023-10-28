// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interfaces/Interaction.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);
	CheckActorUnderMouseCursor();
	HandelHighlighting();
}

void AAuraPlayerController::CheckActorUnderMouseCursor()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	PreviousActorUnderCursor = CurrentActorUnderCursor;
	CurrentActorUnderCursor = Cast<IInteractionInterface>(CursorHit.GetActor());
}

void AAuraPlayerController::HandelHighlighting()
{
	if (CurrentActorUnderCursor == PreviousActorUnderCursor || (!CurrentActorUnderCursor && !PreviousActorUnderCursor))
		return;
	if (!CurrentActorUnderCursor && PreviousActorUnderCursor)
		PreviousActorUnderCursor->UnHighlightActor();
	else if (CurrentActorUnderCursor && !PreviousActorUnderCursor)
		CurrentActorUnderCursor->HighlightActor();
	else if ((CurrentActorUnderCursor && PreviousActorUnderCursor) && (CurrentActorUnderCursor !=
		PreviousActorUnderCursor))
	{
		PreviousActorUnderCursor->UnHighlightActor();
		CurrentActorUnderCursor->HighlightActor();
	}
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraDefaultInputMappingContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(AuraDefaultInputMappingContext, 0);

	bShowMouseCursor = true;
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

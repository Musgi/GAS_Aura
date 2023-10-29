// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/Player/AuraPlayerState.h"

#include "Charachter/Player/AuraPlayerAbilitySystemComponent.h"
#include "Charachter/Player/AuraPlayerAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraPlayerAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UAuraPlayerAttributeSet>("AtttributeSet");
	NetUpdateFrequency = 100.0;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return  CastChecked<UAbilitySystemComponent>(AbilitySystemComponent);
}

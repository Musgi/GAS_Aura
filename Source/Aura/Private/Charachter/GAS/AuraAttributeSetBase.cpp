// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/GAS/AuraAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

void UAuraAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSetBase,MaxHealth,COND_None,REPNOTIFY_Always);
}

void UAuraAttributeSetBase::OnRep_MaxHealth(const FGameplayAttribute& OldMaxHealth) const
{
	//GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSetBase, MaxHealth, OldMaxHealth);
}

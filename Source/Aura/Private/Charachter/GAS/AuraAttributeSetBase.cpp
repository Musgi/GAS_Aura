// Fill out your copyright notice in the Description page of Project Settings.


#include "Charachter/GAS/AuraAttributeSetBase.h"
#include "Net/UnrealNetwork.h"

void UAuraAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSetBase, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSetBase, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSetBase, CurrentMana, COND_None, REPNOTIFY_Always);
	//InitMaxHealth(5);
	//GetMaxHealth();
	//SetMaxHealth(5);
}

void UAuraAttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSetBase, MaxHealth, OldMaxHealth);
	
}

void UAuraAttributeSetBase::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSetBase, CurrentHealth, OldCurrentHealth);
}

void UAuraAttributeSetBase::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSetBase, MaxMana, OldMaxMana);
}

void UAuraAttributeSetBase::OnRep_CurrentMana(const FGameplayAttributeData& OldCurrentMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSetBase, CurrentMana, OldCurrentMana);
}

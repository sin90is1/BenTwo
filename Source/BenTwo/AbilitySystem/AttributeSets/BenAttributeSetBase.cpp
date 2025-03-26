// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AttributeSets/BenAttributeSetBase.h"
#include "GameplayEffectExtension.h"

UBenAttributeSetBase::UBenAttributeSetBase()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitStrength(50.f);
}

void UBenAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}

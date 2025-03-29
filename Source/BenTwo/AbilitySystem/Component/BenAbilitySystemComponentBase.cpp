// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Component/BenAbilitySystemComponentBase.h"
#include "AbilitySystem/BenGameplayAbilityBase.h"

// void UBenAbilitySystemComponentBase::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
// {
// 	for (const TSubclassOf<UGameplayAbility>& AbilityClass : StartupAbilities)
// 	{
// 		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
// 		if (const UBenGameplayAbilityBase* GestureAbility = Cast<UBenGameplayAbilityBase>(AbilitySpec.Ability))
// 		{
// 			AbilitySpec.DynamicAbilityTags.AddTag(GestureAbility->GestureTag);
// 			GiveAbility(AbilitySpec);
// 		}
// 	}
// }

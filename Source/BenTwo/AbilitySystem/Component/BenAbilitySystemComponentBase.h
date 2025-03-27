// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BenAbilitySystemComponentBase.generated.h"

/**
 * 
 */
UCLASS()
class BENTWO_API UBenAbilitySystemComponentBase : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "BenASC")
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);

};

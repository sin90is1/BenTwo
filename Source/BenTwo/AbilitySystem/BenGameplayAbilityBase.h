// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BenGameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class BENTWO_API UBenGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category="Gesture")
	FGameplayTag GestureTag;
};

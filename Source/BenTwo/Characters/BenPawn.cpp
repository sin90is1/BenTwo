// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BenPawn.h"
#include "VRActors/Omnitrix.h"
#include "AbilitySystem/Component/BenAbilitySystemComponentBase.h"

void ABenPawn::GrantAlienAbilities(const FAliens& NewAlien)
{
    // 1. Check if AbilitySystemComponent is valid
    if (!AbilitySystemComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is null!"));
        return;
    }

    // Clear old abilities
    AbilitySystemComponent->ClearAllAbilities();

    if (NewAlien.PoseAbilities.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No abilities defined for alien: %s"), *NewAlien.Name);
        return;
    }

    // Grant new abilities from the map
    for (const auto& Pair : NewAlien.PoseAbilities)
    {
        FGameplayAbilitySpec Spec(Pair.Value, 1); // Pair.Value = Ability Class
        AbilitySystemComponent->GiveAbility(Spec);
    }
}

void ABenPawn::OnPoseDetected(const FString& PoseName, const FAliens& CurrentAlien)
{
    if (CurrentAlien.PoseAbilities.Contains(PoseName))
    {
        TSubclassOf<UGameplayAbility> AbilityClass = CurrentAlien.PoseAbilities[PoseName];
        AbilitySystemComponent->TryActivateAbilityByClass(AbilityClass);
    }
}

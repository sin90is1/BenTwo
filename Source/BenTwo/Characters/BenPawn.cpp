// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BenPawn.h"
#include "VRActors/Omnitrix.h"
#include "AbilitySystem/Component/BenAbilitySystemComponentBase.h"

void ABenPawn::GrantAlienAbilities(const FAliens& NewAlien)
{
    // Clear old abilities
    AbilitySystemComponent->ClearAllAbilities();

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

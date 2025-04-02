// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayAbility.h"
#include "AliensDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FAliens
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FString Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FGameplayTag AlienTag;

    // Static mesh for the alien's hologram
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Alien")
    UStaticMesh* AlienHologram;

    // Material for the alien's hologram
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UMaterialInterface* HandMaterial;

    // Maps pose names (e.g., "Fist") to ability classes
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TMap<FString, TSubclassOf<UGameplayAbility>> PoseAbilities;

};

/**
 * 
 */
UCLASS()
class BENTWO_API UAliensDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FAliens> Aliens;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FAliens Ben;
};

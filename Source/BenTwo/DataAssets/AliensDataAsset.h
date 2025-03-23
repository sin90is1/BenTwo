// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AliensDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FAliens
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FString Name;

    // Static mesh for the alien's hologram
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Alien")
    UStaticMesh* AlienHologram;

    // Material for the alien's hologram
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Alien")
    UMaterialInterface* AlienMaterial;

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
};

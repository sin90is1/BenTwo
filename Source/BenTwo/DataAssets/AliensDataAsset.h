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

//     UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
//     USoundBase* Sound;
// 
//     UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
//     UTexture2D* Image;
// 
//     UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
//     TArray<FString> Abilities;
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

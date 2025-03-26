// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ben2PlayerController.generated.h"

/**
 * 
 */
class AOmnitrix;

UCLASS()
class BENTWO_API ABen2PlayerController : public APlayerController
{
	GENERATED_BODY()


	protected:
    // Reference to the Omnitrix class (set in Blueprint)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Omnitrix")
    TSubclassOf<AOmnitrix> OmnitrixClass;


    UFUNCTION(BlueprintCallable, Category = "Pawn")
    void TransformToAlien(TSubclassOf<APawn> AlienClass);

};

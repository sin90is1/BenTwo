// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BenTwoPawnBase.h"
#include "BenPawn.generated.h"


struct FAliens;
class AOmnitrix;

UCLASS()
class BENTWO_API ABenPawn : public ABenTwoPawnBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Omnitrix")
	void GrantAlienAbilities(const FAliens& NewAlien);

	UFUNCTION(BlueprintCallable, Category = "Omnitrix")
	void OnPoseDetected(const FString& PoseName, const FAliens& CurrentAlien);

protected:
    // Reference to the Omnitrix class (set in Blueprint)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Omnitrix")
    TSubclassOf<AOmnitrix> OmnitrixClass;
};

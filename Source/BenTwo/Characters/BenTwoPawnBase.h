// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BenTwoPawnBase.generated.h"

UCLASS()
class BENTWO_API ABenTwoPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABenTwoPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    // Reference to the Omnitrix class (set in Blueprint)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Omnitrix")
    TSubclassOf<AOmnitrix> OmnitrixClass;

    // Function to spawn the Omnitrix
    UFUNCTION(BlueprintCallable, Category = "Omnitrix")
    void SpawnOmnitrix(USceneComponent* AttachToComponent);

    // Function to get the Omnitrix instance
    UFUNCTION(BlueprintCallable, Category = "Omnitrix")
    class AOmnitrix* GetOmnitrixInstance() const;

private:
    // Reference to the spawned Omnitrix instance (private)
    TObjectPtr<AOmnitrix> OmnitrixInstance;

};

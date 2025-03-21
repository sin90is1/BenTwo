// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssets/AliensDataAsset.h"
#include "Omnitrix.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAlienChangedSignature, const FAliens&, NewAlien);


UCLASS()
class BENTWO_API AOmnitrix : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOmnitrix();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // Reference to the Aliens Data Asset
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Omnitrix")
    UAliensDataAsset* AliensData;

    // Currently chosen alien
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Omnitrix")
    FAliens ChoosenAlien;

    // Multicast delegate for when the chosen alien changes
    UPROPERTY(BlueprintAssignable, Category = "Omnitrix")
    FOnAlienChangedSignature OnAlienChanged;

    // Function to update the chosen alien based on rotation
    UFUNCTION(BlueprintCallable, Category = "Omnitrix")
    void UpdateChosenAlien(float YAxisRotation);

private:
    // Cached segment size
    float SegmentSize;

    // Cached number of aliens
    int32 NumberOfAliens;

    // Initialize cached data
    void InitializeCachedData();
};

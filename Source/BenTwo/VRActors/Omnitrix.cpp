// Fill out your copyright notice in the Description page of Project Settings.


#include "VRActors/Omnitrix.h"

// Sets default values
AOmnitrix::AOmnitrix()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOmnitrix::BeginPlay()
{
	Super::BeginPlay();

    // Initialize cached data
    InitializeCachedData();
}

// Called every frame
void AOmnitrix::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOmnitrix::UpdateChosenAlien(float YAxisRotation)
{
    if (NumberOfAliens == 0)
    {
        // Log a warning if there are no aliens
        return;
    }

    // Normalize the rotation to 0-360 range
    float NormalizedRotation = FMath::Fmod(YAxisRotation + 360.0f, 360.0f);

    // Determine the segment index
    int32 SegmentIndex = FMath::FloorToInt(NormalizedRotation / SegmentSize);

    // Clamp the index to ensure it's within bounds
    SegmentIndex = FMath::Clamp(SegmentIndex, 0, NumberOfAliens - 1);

    // Get the new alien
    FAliens NewAlien = AliensData->Aliens[SegmentIndex];
    //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("New Alien: %s"), *NewAlien.Name));

    // Check if the chosen alien has actually changed
    if (NewAlien.Name != CurrentAlien.Name)
    {
        // Update the chosen alien
        CurrentAlien = NewAlien;

        // Log the chosen alien's name for debugging
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Chosen Alien Updated: %s"), *CurrentAlien.Name));

        // Broadcast the delegate
        OnAlienChanged.Broadcast(CurrentAlien);
    }
    else
    {
        // Log if the chosen alien hasn't changed
        //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("Chosen Alien has not changed."));
    }
}

void AOmnitrix::ConfirmAlienSelection()
{
    OnAlienConfirmed.Broadcast(CurrentAlien);
}

void AOmnitrix::InitializeCachedData()
{
    if (AliensData)
    {
        NumberOfAliens = AliensData->Aliens.Num();
        SegmentSize = 360.0f / NumberOfAliens;
    }
    else
    {
        NumberOfAliens = 0;
        SegmentSize = 0.0f;
    }
    // Debug log for NumberOfAliens (int32) and SegmentSize (float)
    UE_LOG(LogTemp, Warning, TEXT("NumberOfAliens: %d --- SegmentSize: %f"), NumberOfAliens, SegmentSize);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/Ben2PlayerController.h"


void ABen2PlayerController::TransformToAlien(TSubclassOf<APawn> AlienClass)
{
    if (AlienClass)
    {
        // Spawn new alien pawn
        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        APawn* NewAlien = GetWorld()->SpawnActor<APawn>(AlienClass, GetPawn()->GetTransform(), Params);

        // Possess the new pawn
        if (NewAlien)
        {
            APawn* OldPawn2 = GetPawn();
            Possess(NewAlien);
            OldPawn2->Destroy();  // Remove old pawn
        }
    }
}

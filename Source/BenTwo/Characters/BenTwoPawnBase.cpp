// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BenTwoPawnBase.h"
#include "VRActors/Omnitrix.h"

// Sets default values
ABenTwoPawnBase::ABenTwoPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABenTwoPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABenTwoPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABenTwoPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABenTwoPawnBase::SpawnOmnitrix(USceneComponent* AttachToComponent)
{
    if (OmnitrixClass && AttachToComponent)
    {
        // Spawn the Omnitrix actor
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        OmnitrixInstance = GetWorld()->SpawnActor<AOmnitrix>(OmnitrixClass, SpawnParams);

        if (OmnitrixInstance)
        {
            // Attach the Omnitrix to the specified scene component
            OmnitrixInstance->AttachToComponent(AttachToComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

            // Set the Omnitrix's relative location/rotation (if needed)
            OmnitrixInstance->SetActorRelativeLocation(FVector::ZeroVector);
            OmnitrixInstance->SetActorRelativeRotation(FRotator::ZeroRotator);

            UE_LOG(LogTemp, Warning, TEXT("Omnitrix spawned and attached!"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn Omnitrix!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid Omnitrix class or attach component!"));
    }
}

class AOmnitrix* ABenTwoPawnBase::GetOmnitrixInstance() const
{
    // Ensure the instance is valid before returning it
    if (IsValid(OmnitrixInstance))
    {
        return OmnitrixInstance;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("OmnitrixInstance is not valid!"));
        return nullptr;
    }
}


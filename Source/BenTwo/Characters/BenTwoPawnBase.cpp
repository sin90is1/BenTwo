// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BenTwoPawnBase.h"

#include "AbilitySystem/Component/BenAbilitySystemComponentBase.h"
#include "AbilitySystem/AttributeSets/BenAttributeSetBase.h"

// Sets default values
ABenTwoPawnBase::ABenTwoPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    AbilitySystemComponent = CreateDefaultSubobject<UBenAbilitySystemComponentBase>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(false);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

    AttributeSet = CreateDefaultSubobject<UBenAttributeSetBase>("AttributeSetBase");
}

// Called when the game starts or when spawned
void ABenTwoPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABenTwoPawnBase::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    InitAbilityActorInfo();

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

AActor* ABenTwoPawnBase::SpawnObjectAndAttach(USceneComponent* AttachToComponent, TSubclassOf<AActor> ActorClass)
{
    if (ActorClass && AttachToComponent)
    {
        // Spawn the actor
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass, FTransform::Identity, SpawnParams);

        if (SpawnedActor)
        {
            // Attach the actor to the specified scene component
            SpawnedActor->AttachToComponent(AttachToComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

            // Set the spawned actor's relative location/rotation
            SpawnedActor->SetActorRelativeLocation(FVector::ZeroVector);
            SpawnedActor->SetActorRelativeRotation(FRotator::ZeroRotator);

            UE_LOG(LogTemp, Warning, TEXT("Actor spawned and attached successfully!"));

            return SpawnedActor;
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid actor class or attach component!"));
    }

    return nullptr;
}

UAbilitySystemComponent* ABenTwoPawnBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void ABenTwoPawnBase::InitAbilityActorInfo()
{
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
   /* Cast<UBenAbilitySystemComponentBase>(AbilitySystemComponent)->AbilityActorInfoSet();*/
}


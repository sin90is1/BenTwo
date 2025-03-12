// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BenTwoPawnBase.h"

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


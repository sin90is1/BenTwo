// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Pawn.h"
#include "BenTwoPawnBase.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class BENTWO_API ABenTwoPawnBase : public APawn , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABenTwoPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void PossessedBy(AController* NewController) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Omnitrix")
	AActor* SpawnObjectAndAttach(USceneComponent* AttachToComponent, TSubclassOf<AActor> ActorClass);


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetUAttributeSet() const { return AttributeSet; }


protected:

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	void InitAbilityActorInfo();
};

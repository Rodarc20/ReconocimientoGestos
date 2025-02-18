// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "LeapController.h"
#include "CoreMinimal.h"
#include "ClasificadorGestos.h"
#include "GameFramework/Pawn.h"
#include "LeapPawn.generated.h"

UCLASS()
class RECONOCIMIENTOGESTOS_API ALeapPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALeapPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UClasificadorGestos * Clasificador;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "LeapPawn.h"


// Sets default values
ALeapPawn::ALeapPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Clasificador = CreateDefaultSubobject<UClasificadorGestos>(TEXT("ClasificadorGestos"));
}

// Called when the game starts or when spawned
void ALeapPawn::BeginPlay()
{
	Super::BeginPlay();
    
	
}

// Called every frame
void ALeapPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALeapPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


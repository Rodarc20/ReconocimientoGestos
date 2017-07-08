// Fill out your copyright notice in the Description page of Project Settings.

#include "ClasificadorGestos.h"


// Sets default values for this component's properties
UClasificadorGestos::UClasificadorGestos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
    std::cout.rdbuf(&Stream); 
}


// Called when the game starts
void UClasificadorGestos::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UClasificadorGestos::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UClasificadorGestos::AgregarDistanciaDedo(float DistanciaDedo) {
    ManoTemporal.push_back(DistanciaDedo);
}

void UClasificadorGestos::BorrarMano() {
    ManoTemporal.clear();
}
int UClasificadorGestos::ClasificarMano() {
    return Clasificador.Clasificar(ManoTemporal);
}
void UClasificadorGestos::CargarBase() {
    std::cout << "Leyendo Base de datos" << std::endl;
    Clasificador.LeerBaseDatos();
}
void UClasificadorGestos::EscribirBase() {
    Clasificador.EscribirBaseDatos();
}

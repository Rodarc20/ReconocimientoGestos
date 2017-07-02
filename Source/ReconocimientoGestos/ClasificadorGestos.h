// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include<vector>
#include"KNN.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClasificadorGestos.generated.h"



class LStream : public std::stringbuf {
protected:
    int sync() {
        UE_LOG(LogTemp, Log, TEXT("%s"), *FString(str().c_str()));
        str("");
        return std::stringbuf::sync();
    }
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RECONOCIMIENTOGESTOS_API UClasificadorGestos : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClasificadorGestos();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    LStream Stream;

    KNN Clasificador;
    std::vector<double> ManoTemporal;

    UFUNCTION(BlueprintCallable)
    void AgregarDistanciaDedo(float DistanciaDedo);
    UFUNCTION(BlueprintCallable)
    void BorrarMano();
    UFUNCTION(BlueprintCallable)
    int ClasificarMano();
    UFUNCTION(BlueprintCallable)
    void CargarBase();
    UFUNCTION(BlueprintCallable)
    void EscribirBase();
		
	
};

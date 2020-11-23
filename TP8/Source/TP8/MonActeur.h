// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

#include "MonActeur.generated.h"

UCLASS()
class TP8_API AMonActeur : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMonActeur();
	UPROPERTY(VisibleAnywhere)UStaticMeshComponent* MonMaillage;
	UParticleSystemComponent* MonEffetParticules;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};

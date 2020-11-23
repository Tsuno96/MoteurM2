// Fill out your copyright notice in the Description page of Project Settings.


#include "MonActeur.h"

// Sets default values
AMonActeur::AMonActeur()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonActeur::BeginPlay()
{
	UE_LOG(LogActor, Warning, TEXT("∗∗∗∗∗∗ HELLO World FROM GAMAGORA  ! ! ! ! "));
	UE_LOG(LogActor, Warning, TEXT("Actor␣name␣%s "), *this->GetName());
	int out = 10;
	UE_LOG(LogActor, Error, TEXT("Test affichage :  %d"), out);

	FString nom = FString::Printf(TEXT("Nom de l'acteur dans une variable %s "), *(this->GetName()));
	UE_LOG(LogActor, Warning, TEXT("%s"), *nom);
	Super::BeginPlay();
}

// Called every frame
void AMonActeur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


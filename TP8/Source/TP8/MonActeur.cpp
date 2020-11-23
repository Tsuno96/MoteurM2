// Fill out your copyright notice in the Description page of Project Settings.


#include "MonActeur.h"


// Sets default values
AMonActeur::AMonActeur()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Partie III: construction de l'objet VisualMesh
	MonMaillage = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MonMaillage->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	ConstructorHelpers::FObjectFinder<UMaterial> CubeMaterial(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse"));
	if (CubeVisualAsset.Succeeded()) {
		MonMaillage->SetStaticMesh(CubeVisualAsset.Object);
		MonMaillage->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MonMaillage->SetMaterial(0, CubeMaterial.Object);
	}

	MonEffetParticules = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
	MonMaillage->SetupAttachment(MonEffetParticules);

	ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Steam_Lit"));
	MonEffetParticules->SetTemplate(ParticleAsset.Object);
	effetFume = false;

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
	FVector NewLocation = GetActorLocation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * VitesseDeplacement; //Scale our height by a factor of 100;
	/*NewLocation.X += (rand() % 10)-5;
	NewLocation.Y += (rand() % 10)-5;*/
	SetActorLocation(NewLocation);

	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += VitesseRotation;
	SetActorRotation(NewRotation);

	if (effetFume)
	{
		MonEffetParticules->Activate();
	}
	else
	{
		MonEffetParticules->Deactivate();
	}

	Super::Tick(DeltaTime);

}


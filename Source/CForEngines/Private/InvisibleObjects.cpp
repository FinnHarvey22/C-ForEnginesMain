// Fill out your copyright notice in the Description page of Project Settings.


#include "InvisibleObjects.h"
#include "P_FPS.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AInvisibleObjects::AInvisibleObjects()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = _Collider;

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(_Collider);
	

}

// Called when the game starts or when spawned
void AInvisibleObjects::BeginPlay()
{
	Super::BeginPlay();
	
	
}









// Fill out your copyright notice in the Description page of Project Settings.


#include "WinLevelTrigger.h"

#include "P_FPS.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWinLevelTrigger::AWinLevelTrigger()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = _Collider;

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(_Collider);
}

// Called when the game starts or when spawned
void AWinLevelTrigger::BeginPlay()
{
	Super::BeginPlay();
	_Collider->OnComponentHit.AddUniqueDynamic(this, &AWinLevelTrigger::Handle_ColliderHit);
	
}

void AWinLevelTrigger::Handle_ColliderHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::OpenLevel(GetWorld(),TEXT("Level3"),false);
}





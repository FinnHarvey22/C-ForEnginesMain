// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstActor.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Preferences/PersonaOptions.h"


// Sets default values
AFirstActor::AFirstActor()
{
	_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = _Collider;

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(_Collider);

	_Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	_Arrow->SetupAttachment(_Collider);

	//_RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	//_RotatingMovementComponent->Deactivate();

	


}

void AFirstActor::BeginPlay()
{
	Super::BeginPlay();

	_Collider->OnComponentHit.AddUniqueDynamic(this, &AFirstActor::Handle_ColliderHit);
}

void AFirstActor::Handle_ColliderHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Display, TEXT("Hello!!!!!!!!!!!!!!!"));
}


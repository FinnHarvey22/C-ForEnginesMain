// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathBox.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADeathBox::ADeathBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = _Collider;

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(_Collider);
}

void ADeathBox::BeginPlay()
{
	Super::BeginPlay();
	_Collider->OnComponentHit.AddUniqueDynamic(this, &ADeathBox::Handle_ColliderHit);
}


void ADeathBox::Handle_ColliderHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::ApplyDamage(OtherActor, 100000, GetInstigatorController(),
		this, UDamageType::StaticClass());
}




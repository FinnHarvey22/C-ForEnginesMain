// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo_Pickup.h"

#include "P_FPS.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AAmmo_Pickup::AAmmo_Pickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = _Collider;

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(_Collider);
	
}

// Called when the game starts or when spawned
void AAmmo_Pickup::BeginPlay()
{
	Super::BeginPlay();

	_Collider->OnComponentHit.AddUniqueDynamic(this, &AAmmo_Pickup::Handle_ColliderHit);
	
}

void AAmmo_Pickup::Handle_ColliderHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (AP_FPS* PlayerCharacter = Cast<AP_FPS>(OtherActor))
		{
			PlayerCharacter->AddAmmo(m_AmmoPickupAmount);
			UE_LOG(LogTemp, Display, TEXT("Pickup is working!"));
		}
		
		
		Destroy();

		
	}
	
	
}

// Called every frame
void AAmmo_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


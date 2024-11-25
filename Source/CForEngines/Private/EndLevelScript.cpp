// Fill out your copyright notice in the Description page of Project Settings.


#include "EndLevelScript.h"
#include "Widget_EndScreen.h"
#include "AI/NavigationModifier.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEndLevelScript::AEndLevelScript()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEndLevelScript::BeginPlay()
{
	Super::BeginPlay();
	if(_UWidget_EndScreenClass)
	{
		_UWidget_EndScreen = CreateWidget<UWidget_EndScreen>( GetWorld(), _UWidget_EndScreenClass.Get());
		_UWidget_EndScreen->AddToViewport();
	}
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(UGameplayStatics::GetPlayerController(GetWorld(),0),_UWidget_EndScreen);
}

 
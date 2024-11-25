// Fill out your copyright notice in the Description page of Project Settings.


#include "WinLevelScript.h"

#include "Widget_WinScreen.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWinLevelScript::AWinLevelScript()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWinLevelScript::BeginPlay()
{
	Super::BeginPlay();
	
	if(_UWidget_WinScreenClass)
	{
		_UWidget_WinScreen = CreateWidget<UWidget_WinScreen>( GetWorld(), _UWidget_WinScreenClass.Get());
		_UWidget_WinScreen->AddToViewport();
	}
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(UGameplayStatics::GetPlayerController(GetWorld(),0),_UWidget_WinScreen);
	
}




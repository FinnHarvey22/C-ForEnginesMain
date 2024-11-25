// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_EndScreen.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UWidget_EndScreen::NativeConstruct()
{
	Super::NativeConstruct();
	RestartButton->OnPressed.AddUniqueDynamic(this, &UWidget_EndScreen::RestartButtonPressed);
	QuitButton->OnPressed.AddUniqueDynamic(this, &UWidget_EndScreen::QuitButtonPressed);
	
}



void UWidget_EndScreen::RestartButtonPressed()
{
	UGameplayStatics::OpenLevel(GetWorld(),TEXT("Level1"),false);
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetShowMouseCursor(false);
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(UGameplayStatics::GetPlayerController(GetWorld(),0));
}

void UWidget_EndScreen::QuitButtonPressed()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr,EQuitPreference::Quit ,true);
}

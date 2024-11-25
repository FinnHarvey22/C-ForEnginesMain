// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_WinScreen.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"


void UWidget_WinScreen::NativeConstruct()
{
	Super::NativeConstruct();
	RestartButton->OnPressed.AddUniqueDynamic(this, &UWidget_WinScreen::RestartButtonPressed);
	QuitButton->OnPressed.AddUniqueDynamic(this, &UWidget_WinScreen::QuitButtonPressed);
}


void UWidget_WinScreen::RestartButtonPressed()
{
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetShowMouseCursor(false);
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(UGameplayStatics::GetPlayerController(GetWorld(),0));
	UGameplayStatics::OpenLevel(GetWorld(),TEXT("Level1"),false);
}

void UWidget_WinScreen::QuitButtonPressed()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr,EQuitPreference::Quit ,true);
}

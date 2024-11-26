// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_WinScreen.h"

#include "PersistantData.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UWidget_WinScreen::NativePreConstruct()
{
	Super::NativeOnInitialized();
	UE_LOG(LogTemp, Display, TEXT("PreConstruct"))
	PersistantDataInstance = Cast<UPersistantData>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (PersistantDataInstance) {UE_LOG(LogTemp, Display, TEXT("Found Instance"));}
}

void UWidget_WinScreen::NativeConstruct()
{
	Super::NativeConstruct();
	_RestartButton->OnPressed.AddUniqueDynamic(this, &UWidget_WinScreen::RestartButtonPressed);
	_QuitButton->OnPressed.AddUniqueDynamic(this, &UWidget_WinScreen::QuitButtonPressed);
	UE_LOG(LogTemp, Display, TEXT("Score: %d"), PersistantDataInstance->CurrentScore);
	 
	if (_ScoreText) {_ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score:  %d"), PersistantDataInstance->CurrentScore))) ;}

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

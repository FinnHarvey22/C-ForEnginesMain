// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_WinScreen.generated.h"

class UPersistantData;
class UTextBlock;
class UButton;

UCLASS()
class CFORENGINES_API UWidget_WinScreen : public UUserWidget
{
	GENERATED_BODY()

protected:

	
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

	UPersistantData* PersistantDataInstance;
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> _RestartButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> _QuitButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> _ScoreText;

	
	UFUNCTION()
	void RestartButtonPressed();
	UFUNCTION()
	void QuitButtonPressed();

int CurrentScore;
	
};

// Fill out your copyright notice in the Description page of Project Settings.




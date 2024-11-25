// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_WinScreen.generated.h"

	class UButton;
UCLASS()
class CFORENGINES_API UWidget_WinScreen : public UUserWidget
{
	GENERATED_BODY()

protected:

	
	virtual void NativeConstruct() override;


private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> RestartButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> QuitButton;

	
	UFUNCTION()
	void RestartButtonPressed();
	UFUNCTION()
	void QuitButtonPressed();
};

// Fill out your copyright notice in the Description page of Project Settings.




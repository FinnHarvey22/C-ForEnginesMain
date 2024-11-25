// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_EndScreen.generated.h"

class UButton;

UCLASS(Abstract, BlueprintType)
class CFORENGINES_API UWidget_EndScreen : public UUserWidget
{
	
	GENERATED_BODY()
public:
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

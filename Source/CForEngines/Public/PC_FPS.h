// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controlled.h"
#include "GameFramework/PlayerController.h"
#include "PC_FPS.generated.h"


class UWidget_HUD;
struct FInputActionValue;
class UInputAction;
 
UCLASS(Abstract)
class CFORENGINES_API APC_FPS : public APlayerController, public IControlled
{
	GENERATED_BODY()
 
protected:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _LookAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _MoveAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _JumpAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _FireAction;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_HUD> _HUDWidgetClass;
	TObjectPtr<UWidget_HUD> _HUDWidget;
	
 
	virtual void SetupInputComponent() override;
 
	void Look(const FInputActionValue& value);
	void Move(const FInputActionValue& value);
	void JumpPressed();
	void JumpReleased();
	void FirePressed();
	void FireReleased();
	UFUNCTION()
	void HealthChanged(float newHealth, float maxHealth, float changeInHealth);
	
 
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void AddPoints_Implementation(int Score) override;
};

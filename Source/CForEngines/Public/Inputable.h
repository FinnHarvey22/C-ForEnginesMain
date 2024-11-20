﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Inputable.generated.h"
 
UINTERFACE()
class UInputable : public UInterface
{
	GENERATED_BODY()
};
 
class UInputMappingContext;
 
class CFORENGINES_API IInputable
{
	GENERATED_BODY()
 
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_Look(FVector2D value);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_Move(FVector2D value);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_JumpPressed();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_JumpReleased();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_FirePressed();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_FireReleased();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Input_FlipPressed();
    
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UInputMappingContext* GetMappingContext();

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	UBehaviorTree* GetBehaviorTree();
};

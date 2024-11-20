// Fill out your copyright notice in the Description page of Project Settings.


#include "PostProcessingScriptActor.h"


// Sets default values
APostProcessingScriptActor::APostProcessingScriptActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

 void APostProcessingScriptActor::FlipTexture()
{
	if (_PostProcessingEnabled)
	{
		_PostProcessing->Settings.WeightedBlendables.Array[0].Weight = 0;
		_PostProcessingEnabled = !_PostProcessingEnabled;
	}
	else if (!_PostProcessingEnabled)
	{
		_PostProcessing->Settings.WeightedBlendables.Array[0].Weight = 1;
		_PostProcessingEnabled = !_PostProcessingEnabled;
	}
}




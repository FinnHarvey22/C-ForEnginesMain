#pragma once
 
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_HUD.generated.h"
 
class UTextBlock;
class UProgressBar;
 
UCLASS(Abstract, BlueprintType)
class CFORENGINES_API UWidget_HUD : public UUserWidget
{
	GENERATED_BODY()
 
public:
	virtual void NativeConstruct() override;
	void UpdateHealth(float newHealthRatio);
	void UpdateScore(int newScore);
	void UpdateAmmo(int count);
 
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ScoreText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> AmmoText;
	int currentScore = 0;
	int currentAmmo = 0;
};
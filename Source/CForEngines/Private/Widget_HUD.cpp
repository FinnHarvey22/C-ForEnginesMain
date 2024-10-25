#include "Widget_HUD.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
 
void UWidget_HUD::NativeConstruct()
{
	Super::NativeConstruct();
 
	if(HealthBar) { HealthBar->SetPercent(1.f); }
 
	if(ScoreText) { ScoreText->SetText(FText::FromString("Score: 0")); }
}
 
void UWidget_HUD::UpdateHealth(float newHealthRatio)
{
	if(HealthBar) { HealthBar->SetPercent(newHealthRatio); }
}
 
void UWidget_HUD::UpdateScore(int newScore)
{
	currentScore += newScore;
	if(ScoreText)
	{
		ScoreText->SetText(
		   FText::FromString(
			  FString::Printf(TEXT("Score: %d"), currentScore)
		   )
		);
	}
}
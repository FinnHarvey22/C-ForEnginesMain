
#include "CForEngines/Public/PC_FPS.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "P_FPS.h"
#include "Widget_HUD.h"
#include "Blueprint/UserWidget.h"
#include "CForEngines/Public/Inputable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "WorldPartition/DataLayer/DataLayerSubsystem.h"


void APC_FPS::BeginPlay()
{
   Super::BeginPlay();
   if(_HUDWidgetClass)
   {
      _HUDWidget = CreateWidget<UWidget_HUD, APC_FPS*>( this, _HUDWidgetClass.Get());
      _HUDWidget->AddToViewport();
   }


  
}

void APC_FPS::AddPoints_Implementation(int Score)
{
   
   _HUDWidget->UpdateScore(Score);
}

void APC_FPS::SetAmmo_Implementation(int count)
{
   
   _HUDWidget->UpdateAmmo(count);
}

FGenericTeamId APC_FPS::GetGenericTeamId() const
{
  
   FGenericTeamId _teamID = FGenericTeamId(2);
   return  _teamID;
}

void APC_FPS::SetupInputComponent()
{
    Super::SetupInputComponent();
 
    if(UEnhancedInputComponent* EIP = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
       EIP->BindAction(_LookAction, ETriggerEvent::Triggered, this, &APC_FPS::Look);
       EIP->BindAction(_MoveAction, ETriggerEvent::Triggered, this, &APC_FPS::Move);
       //EIP->BindAction(_JumpAction, ETriggerEvent::Triggered, this, &APC_FPS::JumpPressed);
       //EIP->BindAction(_JumpAction, ETriggerEvent::Completed, this, &APC_FPS::JumpReleased);
       EIP->BindAction(_FireAction, ETriggerEvent::Triggered, this, &APC_FPS::FirePressed);
       EIP->BindAction(_FireAction, ETriggerEvent::Completed, this, &APC_FPS::FireReleased);
       EIP->BindAction(_FlipAction, ETriggerEvent::Started, this, &APC_FPS::FlipPressed);
    }
}
 
void APC_FPS::Look(const FInputActionValue& value)
{
    FVector2D LookVector = value.Get<FVector2D>();
 
    if(APawn* currentPawn = GetPawn())
    {
       
       if(UKismetSystemLibrary::DoesImplementInterface(currentPawn, UInputable::StaticClass()))
       {
          IInputable::Execute_Input_Look(currentPawn, LookVector);
          
       }
    }
}
 
void APC_FPS::Move(const FInputActionValue& value)
{
    FVector2D MoveVector = value.Get<FVector2D>();
 
    if(APawn* currentPawn = GetPawn())
    {
       if(UKismetSystemLibrary::DoesImplementInterface(currentPawn, UInputable::StaticClass()))
       {
          IInputable::Execute_Input_Move(currentPawn, MoveVector);
       }
    }
}
 
// void APC_FPS::JumpPressed()
// {
//     if(APawn* currentPawn = GetPawn())
//     {
//        if(UKismetSystemLibrary::DoesImplementInterface(currentPawn, UInputable::StaticClass()))
//        {
//           IInputable::Execute_Input_JumpPressed(currentPawn);
//        }
//     }
// }
 
// void APC_FPS::JumpReleased()
// {
//     if(APawn* currentPawn = GetPawn())
//     {
//        if(UKismetSystemLibrary::DoesImplementInterface(currentPawn, UInputable::StaticClass()))
//        {
//           IInputable::Execute_Input_JumpReleased(currentPawn);
//        }
//     }
// }
 
void APC_FPS::FirePressed()
{
 
      if(APawn* currentPawn = GetPawn())
      {
         if(UKismetSystemLibrary::DoesImplementInterface(currentPawn, UInputable::StaticClass()))
         {
            IInputable::Execute_Input_FirePressed(currentPawn);
         }
      }
   
}
 
void APC_FPS::FireReleased()
{
    if(APawn* currentPawn = GetPawn())
    {
       if(UKismetSystemLibrary::DoesImplementInterface(currentPawn, UInputable::StaticClass()))
       {
          IInputable::Execute_Input_FireReleased(currentPawn);
       }
    }
}



void APC_FPS::FlipPressed()
{
   UE_LOG(LogTemp, Display, TEXT("Function Running"));
   if(UDataLayerSubsystem* DataLayerSubsystem = UWorld::GetSubsystem<UDataLayerSubsystem>(GetWorld()))
   {
      UE_LOG(LogTemp, Display, TEXT("Got DatalayerSubsystem"));
      if (_PostProcessingEnabled)
      {
         DataLayerSubsystem->SetDataLayerInstanceRuntimeState(_InvisibleObjectsDataLayer, EDataLayerRuntimeState::Unloaded);
         DataLayerSubsystem->SetDataLayerInstanceRuntimeState(_VisibleObjectsDataLayer, EDataLayerRuntimeState::Activated);
         _PostProcessingEnabled = !_PostProcessingEnabled;
         UE_LOG(LogTemp, Display, TEXT("Post Processing disabled" ));
      }
      else if (!_PostProcessingEnabled)
      {
        DataLayerSubsystem->SetDataLayerInstanceRuntimeState(_InvisibleObjectsDataLayer, EDataLayerRuntimeState::Activated);
        DataLayerSubsystem->SetDataLayerInstanceRuntimeState(_VisibleObjectsDataLayer, EDataLayerRuntimeState::Unloaded);
         _PostProcessingEnabled = !_PostProcessingEnabled;
         UE_LOG(LogTemp, Display, TEXT("Post Processing Enabled"));
      }
   }
}

void APC_FPS::HealthChanged(float newHealth, float maxHealth, float changeInHealth)
{
  float CurrentHealthRatio = (newHealth/maxHealth);
   
   _HUDWidget->UpdateHealth(CurrentHealthRatio);
   
}

void APC_FPS::OnDeath()
{
   UE_LOG(LogTemp, Display, TEXT("You Have Died"));
   
}






void APC_FPS::OnPossess(APawn* InPawn)
{
   Super::OnPossess(InPawn);
 
   if(UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
   {
      if(UKismetSystemLibrary::DoesImplementInterface(InPawn, UInputable::StaticClass()))
      {
         subsystem->AddMappingContext(IInputable::Execute_GetMappingContext(InPawn), 0);
      }
   }

   
   if (AP_FPS* PlayerCharacter = Cast<AP_FPS>(GetPawn()))
   {
      PlayerCharacter->OnHealthChangedDelagate.AddUniqueDynamic(this, &APC_FPS::HealthChanged);
      PlayerCharacter->OnDeathDelagate.AddUniqueDynamic(this, &APC_FPS::OnDeath);
      PlayerCharacter->OnAmmoChangedDelagate.AddUniqueDynamic(this, &APC_FPS::SetAmmo_Implementation);
   }
}

   





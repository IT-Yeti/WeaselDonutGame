// Fill out your copyright notice in the Description page of Project Settings.


#include "DashAbility.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "InputCoreTypes.h"
// Sets default values for this component's properties
UDashAbility::UDashAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDashAbility::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDashAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Timer+=DeltaTime;
	// ...
}

void UDashAbility::Dash(APawn* Character) 
{
	APlayerController* CharacterController = Cast<APlayerController>(Character->GetController());
	if(Timer<Cooldown)
	{
		return;
	}
	if(CharacterController)
	{
		if(CharacterController->IsInputKeyDown(FKey(TEXT("D"))) || CharacterController->IsInputKeyDown(FKey(TEXT("A"))))
		{
			Character->LaunchPawn(GetOwner()->GetActorForwardVector()*DashPower,false,false);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("W"))))
		{
			Character->LaunchPawn(GetOwner()->GetActorUpVector()*DashPower,false,false);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("S"))))
		{
			Character->LaunchPawn(GetOwner()->GetActorUpVector()*DashPower*-1,false,false);
		}
		else
		{
			Character->LaunchPawn(GetOwner()->GetActorForwardVector()*DashPower,false,false);
		}
	}
	Timer=0;
	
}


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

	// ...
}

void UDashAbility::Dash(ACharacter* Character, bool IsAttached) 
{
	APlayerController* CharacterController = Cast<APlayerController>(Character->GetController());
	if(CharacterController)
	{
		if(CharacterController->IsInputKeyDown(FKey(TEXT("D"))) || CharacterController->IsInputKeyDown(FKey(TEXT("A"))))
		{
			Character->LaunchCharacter(GetOwner()->GetActorForwardVector()*1000,false,false);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("W"))))
		{
			Character->LaunchCharacter(GetOwner()->GetActorUpVector()*1000,false,false);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("S"))))
		{
			Character->LaunchCharacter(GetOwner()->GetActorUpVector()*1000*-1,false,false);
		}
		else
		{
			Character->LaunchCharacter(GetOwner()->GetActorForwardVector()*1000,false,false);
		}
	}
	
}


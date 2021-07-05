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
		UStaticMeshComponent* StaticMeshRef = Character->FindComponentByClass<UStaticMeshComponent>();
		if(!StaticMeshRef)
		{
			return;
			UE_LOG(LogTemp,Warning,TEXT("There are no Mesh reference"));
		}

		if(CharacterController->IsInputKeyDown(FKey(TEXT("A"))))
		{
			UE_LOG(LogTemp,Warning,TEXT("Dashing Forwards"));
			StaticMeshRef->AddForce(FVector(0.f,-DashPower,0.f),FName(TEXT("None")),true);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("D"))))
		{
			StaticMeshRef->AddForce(FVector(0.f,DashPower,0.f),FName(TEXT("None")),true);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("W"))))
		{
			StaticMeshRef->AddImpulse(FVector(0,0,DashPower),FName(TEXT("None")),true);
		}
		else if(CharacterController->IsInputKeyDown(FKey(TEXT("S"))))
		{
			StaticMeshRef->AddImpulse(FVector(0,0,-DashPower),FName(TEXT("None")),true);
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("Actor Forward Vector:%s"),*Character->GetActorForwardVector().ToString());
			StaticMeshRef->AddImpulse(FVector(0,DashPower,0),FName(TEXT("None")),true);
		}
	}
	Timer=0;
	
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Helper.h"
#include "Components/InputComponent.h"

// Sets default values
AHelper::AHelper()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHelper::BeginPlay()
{
	Super::BeginPlay();
	StaticMeshRef = FindComponentByClass<UStaticMeshComponent>();
	if(StaticMeshRef)
	{
		UE_LOG(LogTemp,Warning,TEXT("I found static mesh"));
	}
}

// Called every frame
void AHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHelper::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRightArrows", this, &AHelper::MoveRight);
}

void AHelper::MoveRight(float Value) 
{
	UE_LOG(LogTemp,Warning,TEXT("Yo"));
	StaticMeshRef->AddForce(FVector(0.f, -Value * 500 * GetWorld()->GetDeltaSeconds(), 0.f));
}


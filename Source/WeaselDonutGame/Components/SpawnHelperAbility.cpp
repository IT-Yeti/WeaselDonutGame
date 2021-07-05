// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnHelperAbility.h"
#include "Components/StaticMeshComponent.h"
// Sets default values for this component's properties
USpawnHelperAbility::USpawnHelperAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	HelperMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("HelperBody"));
}


// Called when the game starts
void USpawnHelperAbility::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnHelperAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnHelperAbility::SpawnHelper() 
{
	
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DashAbility.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEASELDONUTGAME_API UDashAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDashAbility();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void Dash(ACharacter* Character);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Dash")
	float DashPower = 1000;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Dash")
	float Cooldown = 5;
	float Timer;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	


		
};

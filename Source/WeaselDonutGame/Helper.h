// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Helper.generated.h"

UCLASS()
class WEASELDONUTGAME_API AHelper : public APawn
{
	GENERATED_BODY()

public:
	AHelper();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void MoveRight(float Value);

protected:
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent* StaticMeshRef;
};

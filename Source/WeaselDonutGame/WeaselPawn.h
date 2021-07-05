// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WeaselPawn.generated.h"

UCLASS()
class WEASELDONUTGAME_API AWeaselPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weasel", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weasel", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weasel", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weasel", meta = (AllowPrivateAccess = "true"))
	class UDashAbility* DashAbility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weasel", meta = (AllowPrivateAccess = "true"))
	float ForceAcceleration;


public:
	// Sets default values for this pawn's properties
	AWeaselPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(float Value);

	void Dash();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintImplementableEvent)
	void Detach();
};

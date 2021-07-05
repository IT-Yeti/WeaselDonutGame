// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnHelperAbility.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEASELDONUTGAME_API USpawnHelperAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	USpawnHelperAbility();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void SpawnHelper();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere,meta=(AllowPrivateAccess = "true"))
	UStaticMesh* HelperMesh;

		
};

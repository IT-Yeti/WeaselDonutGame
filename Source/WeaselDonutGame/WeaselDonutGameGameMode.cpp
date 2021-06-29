// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeaselDonutGameGameMode.h"
#include "WeaselDonutGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeaselDonutGameGameMode::AWeaselDonutGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

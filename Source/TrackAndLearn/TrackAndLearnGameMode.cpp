// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrackAndLearnGameMode.h"
#include "TrackAndLearnCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrackAndLearnGameMode::ATrackAndLearnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

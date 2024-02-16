// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"   
#include "TrackAndLearnCharacter.h"
#include "ArrivalActor.generated.h"

UCLASS()
class TRACKANDLEARN_API AArrivalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrivalActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable, WithValidation)
	void PlayerReachedEnd(ATrackAndLearnCharacter* PlayerCharacter);

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:

};

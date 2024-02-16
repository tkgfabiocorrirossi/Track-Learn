// Fill out your copyright notice in the Description page of Project Settings.


#include "ArrivalActor.h"
#include <Engine/TriggerBase.h>
#include <Components/BoxComponent.h>

// Sets default values
AArrivalActor::AArrivalActor()
{
    // Initialize the collision component
    UBoxComponent* CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
    RootComponent = CollisionComponent;
    CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

}

// Called when the game starts or when spawned
void AArrivalActor::BeginPlay()
{
}

void AArrivalActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
    // Cast OtherActor to your player character class to ensure it's a player
    ATrackAndLearnCharacter* PlayerCharacter = Cast<ATrackAndLearnCharacter>(OtherActor);
    if (PlayerCharacter != nullptr)
    {
        // Call a server-side function to handle the player reaching the cube
        PlayerReachedEnd(PlayerCharacter);
    }
}

void AArrivalActor::PlayerReachedEnd_Implementation(ATrackAndLearnCharacter* PlayerCharacter)
{
    if (HasAuthority())
    {
        UE_LOG(LogTemp, Warning, TEXT("%s reached the end!"), *PlayerCharacter->GetName());
        if(GetWorld())
        {
            FGenericPlatformMisc::RequestExit(false);
        }
    }
}

bool AArrivalActor::PlayerReachedEnd_Validate(ATrackAndLearnCharacter* PlayerCharacter)
{
    // Validation logic here, return true if valid
    return true;
}

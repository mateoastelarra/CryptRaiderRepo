// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerArea.h"


// Sets default values for this component's properties
UTriggerArea::UTriggerArea()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTriggerArea::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UTriggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Actor = GetAccepableActor();
	if (Actor != nullptr)
	{
		
		if (Mover != nullptr)
		{
			Mover->SetShouldMove(true);
			UE_LOG(LogTemp, Display, TEXT("It Has Actor: %s and MOVER"), *Actor->GetActorNameOrLabel())
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("It Has Actor: %s"), *Actor->GetActorNameOrLabel())
		}
			
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Actor"))
		if (Mover != nullptr)
			Mover->SetShouldMove(false);
	}
	
}

AActor* UTriggerArea::GetAccepableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(UnlockActorTag))
		{
			return Actor;
		}	
	}	

	return nullptr;
}

void UTriggerArea::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}

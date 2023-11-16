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
		UE_LOG(LogTemp, Display, TEXT("It Has Actor: %s"), *Actor->GetActorNameOrLabel())
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Actor"))
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

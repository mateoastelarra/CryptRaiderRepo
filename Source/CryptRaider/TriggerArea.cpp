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
	
	ActivateAndDeActivateMovement();
}

void UTriggerArea::ActivateAndDeActivateMovement()
{
	if (Mover == nullptr) { return; }
	AActor* Actor = GetAccepableActor();
	if (Actor != nullptr)
	{
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr)
		{
			Component->SetSimulatePhysics(false);
			Actor->AttachToActor(this->GetAttachmentRootActor(), FAttachmentTransformRules::KeepWorldTransform);
		}
		Mover->SetShouldMove(true);	
	}
	else
	{
		Mover->SetShouldMove(false);
	}
}

AActor* UTriggerArea::GetAccepableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		bool HasAcceptableTag = Actor->ActorHasTag(UnlockActorTag);
		bool IsGrabbed = Actor->ActorHasTag("Grabbed");
		if (HasAcceptableTag && !IsGrabbed)
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

// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerArea.h"


// Sets default values for this component's properties
UTriggerArea::UTriggerArea()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...|
}

// Called when the game starts
void UTriggerArea::BeginPlay()
{
	Super::BeginPlay();

    UE_LOG(LogTemp, Display, TEXT("That Son Of a Bitch Made it"));
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...|
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FString ShouldMoveBool = ShouldMove? "True" : "False";
	UE_LOG(LogTemp, Display, TEXT("Should Move: %s"), *ShouldMoveBool)
	if (ShouldMove)
	{
		AActor* Owner = GetOwner();
		FVector CurrentPosition = Owner->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewPosition = FMath::VInterpConstantTo(CurrentPosition, TargetLocation, DeltaTime, Speed);
		Owner->SetActorLocation(NewPosition);
	}	
}

void UMover::SetShouldMove(bool move)
{
	ShouldMove = move;
}


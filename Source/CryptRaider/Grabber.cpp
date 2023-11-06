// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabbingDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);		
}

void UGrabber::Grab()
{
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabbingDistance;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult, 
		Start, 
		End, 
		FQuat::Identity, 
		ECC_GameTraceChannel2,
		Sphere
	);
	
	if (HasHit)
	{
		AActor* HitActor = HitResult.GetActor();
		FString ActorName = HitActor->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("Actors Name: %s"), *ActorName);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Actor Being Hit"));
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Release Grabber"));
}



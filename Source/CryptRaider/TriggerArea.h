// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerArea.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UTriggerArea : public UBoxComponent
{
	GENERATED_BODY()
	
public:	
// Sets default values for this component's properties
UTriggerArea();

protected:
// Called when the game starts
virtual void BeginPlay() override;

};

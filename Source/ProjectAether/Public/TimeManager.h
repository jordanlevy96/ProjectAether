// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimeManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTAETHER_API UTimeManager : public UObject
{
	GENERATED_BODY()
	
public:
	UTimeManager();

	UFUNCTION(BlueprintCallable)
	void PauseTime();

	UFUNCTION(BlueprintCallable)
	void ResumeTime();
	
	UFUNCTION(BlueprintCallable)
	void SetTimeScale(float NewTimeScale);

protected:
	float TimeScaleBeforePause;
};

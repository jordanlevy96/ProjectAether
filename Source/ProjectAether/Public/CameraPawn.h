// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpectatorPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h" 
#include "CameraPawn.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAETHER_API ACameraPawn : public ASpectatorPawn
{
	GENERATED_BODY()

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	float GetCurrentPanSpeed() const;

	virtual void MoveForward(const FInputActionValue& Value);
	virtual void MoveBackward(const FInputActionValue& Value);
	virtual void MoveRight(const FInputActionValue& Value);
	virtual void MoveLeft(const FInputActionValue& Value);

	void Zoom(const FInputActionValue& Value);

	void MouseLook(const FInputActionValue& Value);
	void OnRightClickPressed();
	void OnRightClickReleased();

	bool bIsRightClickHeld = false;
	
public:
	ACameraPawn();
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float LookSensitivity = 0.75f;

	// Pan and Zoom Speed Settings
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	float MediumZoomThreshold = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	float HighZoomThreshold = 100000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	float ClosePanSpeed = 200.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	float MediumPanSpeed = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	float HighPanSpeed = 1600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CloseZoomSpeed = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MediumZoomSpeed = 2000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float HighZoomSpeed = 5000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MinZoom = -1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MaxZoom = 1000000.0f;
};

#include "CameraPawn.h"

ACameraPawn::ACameraPawn()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false; // Avoid the camera adjusting its position based on collision
	SpringArm->TargetArmLength = 800.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

	// TODO: set dynamically based on player capital or something
	SetActorLocation(FVector(2690, 21220, 3000));
	SpringArm->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
}

void ACameraPawn::OnRightClickPressed()
{
	bIsRightClickHeld = true;
}

void ACameraPawn::OnRightClickReleased()
{
	bIsRightClickHeld = false;
}

void ACameraPawn::MouseLook(const FInputActionValue& Value)
{
	if (bIsRightClickHeld)
	{
		const FVector2D MouseDelta = Value.Get<FVector2D>() * LookSensitivity;
		
		FRotator NewRotation = SpringArm->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + MouseDelta.Y, -80.f, 80.f); // Limit pitch to avoid flipping
		NewRotation.Yaw += MouseDelta.X;

		SpringArm->SetWorldRotation(NewRotation);
	}
}

void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	const UInputAction* MoveForwardAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_MoveForward"));
	const UInputAction* MoveBackwardAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_MoveBackward"));
	const UInputAction* MoveRightAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_MoveRight"));
	const UInputAction* MoveLeftAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_MoveLeft"));

	const UInputAction* ZoomAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_Zoom"));
	
	const UInputAction* MouseLookAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_MouseLook"));
	const UInputAction* RightClickAction = FindObject<UInputAction>(ANY_PACKAGE, TEXT("IA_ClickRight"));
	
	EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ACameraPawn::MoveForward);
	EnhancedInputComponent->BindAction(MoveBackwardAction, ETriggerEvent::Triggered, this, &ACameraPawn::MoveBackward);
	EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ACameraPawn::MoveRight);
	EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Triggered, this, &ACameraPawn::MoveLeft);

	EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ACameraPawn::Zoom);

	EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ACameraPawn::MouseLook);
	EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Started, this, &ACameraPawn::OnRightClickPressed);
	EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Completed, this, &ACameraPawn::OnRightClickReleased);
}

float ACameraPawn::GetCurrentPanSpeed() const
{
	if (SpringArm->TargetArmLength <= MediumZoomThreshold)
	{
		return ClosePanSpeed;
	}
	else if (SpringArm->TargetArmLength <= HighZoomThreshold)
	{
		// Smooth transition between MediumPanSpeed and ClosePanSpeed
		float Alpha = (SpringArm->TargetArmLength - MediumZoomThreshold) / (HighZoomThreshold - MediumZoomThreshold);
		return FMath::Lerp(MediumPanSpeed, ClosePanSpeed, Alpha);
	}
	else
	{
		// Smooth transition between HighPanSpeed and MediumPanSpeed
		float Alpha = (SpringArm->TargetArmLength - HighZoomThreshold) / (MaxZoom - HighZoomThreshold);
		return FMath::Lerp(HighPanSpeed, MediumPanSpeed, Alpha);
	}
}

void ACameraPawn::MoveForward(const FInputActionValue& Value)
{
	float CurrentPanSpeed = GetCurrentPanSpeed();
	FVector MoveDirection = SpringArm->GetForwardVector() * Value.Get<float>() * CurrentPanSpeed;
	MoveDirection.Z = 0;
	SetActorLocation(GetActorLocation() + MoveDirection, true);
}

void ACameraPawn::MoveBackward(const FInputActionValue& Value)
{
	float CurrentPanSpeed = GetCurrentPanSpeed();
	FVector MoveDirection = SpringArm->GetForwardVector() * -Value.Get<float>() * CurrentPanSpeed;
	MoveDirection.Z = 0;
	SetActorLocation(GetActorLocation() + MoveDirection, true);
}

void ACameraPawn::MoveRight(const FInputActionValue& Value)
{
	float CurrentPanSpeed = GetCurrentPanSpeed();
	FVector MoveDirection = SpringArm->GetRightVector() * Value.Get<float>() * CurrentPanSpeed;
	MoveDirection.Z = 0;
	SetActorLocation(GetActorLocation() + MoveDirection, true);
}

void ACameraPawn::MoveLeft(const FInputActionValue& Value)
{
	float CurrentPanSpeed = GetCurrentPanSpeed();
	FVector MoveDirection = SpringArm->GetRightVector() * -Value.Get<float>() * CurrentPanSpeed;
	MoveDirection.Z = 0;
	SetActorLocation(GetActorLocation() + MoveDirection, true);
}

void ACameraPawn::Zoom(const FInputActionValue& Value)
{
	const float AxisValue = -Value.Get<float>();
	float ZoomSpeed;

	if (SpringArm->TargetArmLength <= MediumZoomThreshold)
	{
		ZoomSpeed = CloseZoomSpeed;
	}
	else if (SpringArm->TargetArmLength <= HighZoomThreshold)
	{
		ZoomSpeed =  MediumZoomSpeed;
	}
	else
	{
		ZoomSpeed = HighZoomSpeed;
	}
	
	if (AxisValue != 0.f)
	{
		SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength + AxisValue * ZoomSpeed, MinZoom, MaxZoom);
		// UE_LOG(LogTemp, Warning, TEXT("Zoom, Speed: %f, %f"), SpringArm->TargetArmLength, ZoomSpeed);
	}
}

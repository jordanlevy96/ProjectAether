#include "Building.h"

// Sets default values
ABuilding::ABuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilding::AlignToLandscape()
{
	UE_LOG(LogTemp, Warning, TEXT("Aligning %s"), *GetName());
	if(GEngine && GetWorld())
	{
		FVector BuildingLocation = GetActorLocation();
		FVector StartTrace = BuildingLocation + FVector(0.0f, 0.0f, 500.0f); // Start 500 units above the building
		FVector EndTrace = BuildingLocation - FVector(0.0f, 0.0f, 5000.0f); // End 5000 units below the building
        
		FHitResult HitResult;
		FCollisionQueryParams TraceParams(FName(TEXT("LandscapeTrace")), true, this);
		TraceParams.bReturnPhysicalMaterial = false;

		// Perform the trace
		bool bHit = GetWorld()->LineTraceSingleByChannel(
			HitResult, 
			StartTrace, 
			EndTrace, 
			ECC_WorldStatic, // Make sure this channel only interacts with the landscape
			TraceParams
		);

		if(bHit)
		{
			// Align the building's up vector with the normal of the hit point
			FRotator NewRotation = FRotationMatrix::MakeFromZ(HitResult.ImpactNormal).Rotator();
			SetActorRotation(NewRotation);

			// Move the building down to the hit location
			SetActorLocation(HitResult.Location);
		}
	}
}


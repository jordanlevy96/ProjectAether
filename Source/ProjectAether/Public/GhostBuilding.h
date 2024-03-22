#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "GhostBuilding.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAETHER_API AGhostBuilding : public ABuilding
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void InitializeGhost(UStaticMesh* BuildingMesh, UMaterialInterface* GhostMaterial);

	UFUNCTION(BlueprintCallable)
	void CheckForCollisions(UMaterialInterface* ValidMaterial, UMaterialInterface* InvalidMaterial);
	
	static void UpdateMaterial(UMaterialInterface* Material, UStaticMeshComponent* Mesh);
	
	UStaticMeshComponent* GhostMesh;

public:
	UPROPERTY(BlueprintReadOnly)
	bool bIsValidLocation;
};


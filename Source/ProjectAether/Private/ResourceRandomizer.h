#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceNode.h"
#include "Landscape.h"
#include "PCGVolume.h"
#include "ResourceRandomizer.generated.h"

UCLASS()
class AResourceRandomizer : public AActor
{
	GENERATED_BODY()

	ALandscape* FindLandscapeActor() const;
	
public:	
	// Sets default values for this actor's properties
	AResourceRandomizer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PCG")
	APCGVolume* PCGVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> ClayResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> StoneResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> BitumenResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> GoldResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> SilverResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> CopperResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> TinResourceClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Classes")
	TSubclassOf<AResourceNode> TreesResourceClass;

};

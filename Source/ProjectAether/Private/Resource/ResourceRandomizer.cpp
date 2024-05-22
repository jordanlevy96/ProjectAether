#include "Resource/ResourceRandomizer.h"

#include "EngineUtils.h"
#include "Misc/LowLevelTestAdapter.h"

// Sets default values
AResourceRandomizer::AResourceRandomizer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ALandscape* AResourceRandomizer::FindLandscapeActor() const
{
	ALandscape* FoundLandscape = nullptr;

	for (TActorIterator<ALandscape> It(GetWorld()); It; ++It)
	{
		ALandscape* Landscape = *It;
		if (!FoundLandscape)
		{
			UE_LOG(LogTemp, Warning, TEXT("Landscape %s"), *It->GetName())
			FoundLandscape = Landscape;
		}
	}

	return FoundLandscape;
}

// Called when the game starts or when spawned
void AResourceRandomizer::BeginPlay()
{
	Super::BeginPlay();

	int Seed = GetTypeHash(&TEXT("test")); // TODO: user input
	UWorld* World = GetWorld();
	ALandscape* Landscape = FindLandscapeActor();
	if (Landscape == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("No Landscape actor found. Please ensure a landscape is present in the level."));
		return; 
	}
	UWorldPartition* WorldPartition = GetWorld()->GetWorldPartition();
	if (!WorldPartition)
	{
		UE_LOG(LogTemp, Error, TEXT("World Partition is not enabled in this level."));
		return;
	}
	FVector Origin, BoxExtent;
	Landscape->GetActorBounds(false, Origin, BoxExtent);
	FVector LandscapeSize = BoxExtent * 2; // Total size

	UE_LOG(LogTemp, Warning, TEXT("Landscape Origin: %s"), *Origin.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Landscape Size: %s"), *LandscapeSize.ToString());


	FRandomStream RandomStream;
	RandomStream.Initialize(Seed); 

	int GridSize = 100; // Grid cell size

	for (float X = 0; X < LandscapeSize.X; X += GridSize)
	{
		for (float Y = 0; Y < LandscapeSize.Y; Y += GridSize)
		{
			FVector Location = FVector(X, Y, 100);
			World->SpawnActor<AResourceNode>(StoneResourceClass, Location, FRotator::ZeroRotator);
			UE_LOG(LogTemp, Warning, TEXT("Spawned Stone: %f %f"), X, Y);
			// FBiomeProperties Biome = GetBiomePropertiesAtLocation(Location); // Implement this
			// PlaceResources(Biome, Location, RandomStream);
		}
	}
}

// Called every frame
void AResourceRandomizer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


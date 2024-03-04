#include "Family.h"

// Sets default values
AFamily::AFamily()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFamily::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFamily::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


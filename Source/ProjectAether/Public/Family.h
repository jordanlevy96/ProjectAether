#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Family.generated.h"

UCLASS()
class PROJECTAETHER_API AFamily : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFamily();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

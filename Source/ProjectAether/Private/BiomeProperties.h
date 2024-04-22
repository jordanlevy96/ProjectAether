#pragma once

#include "Engine/DataTable.h"
#include "BiomeProperties.generated.h"

USTRUCT(BlueprintType)
struct FBiomeProperties : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ZStart;

	// Minerals
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Clay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Stone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Bitumen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Gold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Silver;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Copper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Tin;

	// Flora

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Trees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Reeds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cotton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Papyrus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Flax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cannabis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Wheat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Barley;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Onions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Garlic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Lentils;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Chickpeas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Grapes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Olives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Figs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cucumbers;

	// Fauna

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cattle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Sheep;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Goats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Pigs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Donkeys;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Horses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Camels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Bees;
};
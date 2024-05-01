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

	// set default constructor
	// FBiomeProperties()
	// : Color(FColor::White)
	// , ZStart(0.0f)
	// , Clay(0.0f)
	// , Stone(0.0f)
	// , Bitumen(0.0f)
	// , Gold(0.0f)
	// , Silver(0.0f)
	// , Copper(0.0f)
	// , Tin(0.0f)
	// , Trees(0.0f)
	// , Reeds(0.0f)
	// , Cotton(0.0f)
	// , Papyrus(0.0f)
	// , Flax(0.0f)
	// , Cannabis(0.0f)
	// , Wheat(0.0f)
	// , Barley(0.0f)
	// , Onions(0.0f)
	// , Garlic(0.0f)
	// , Lentils(0.0f)
	// , Chickpeas(0.0f)
	// , Grapes(0.0f)
	// , Olives(0.0f)
	// , Figs(0.0f)
	// , Cucumbers(0.0f)
	// , Cattle(0.0f)
	// , Sheep(0.0f)
	// , Goats(0.0f)
	// , Pigs(0.0f)
	// , Donkeys(0.0f)
	// , Horses(0.0f)
	// , Camels(0.0f)
	// , Bees(0.0f)
	// {
	// }
};
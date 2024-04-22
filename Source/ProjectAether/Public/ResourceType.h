#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	// Minerals and construction materials
	Clay UMETA(DisplayName = "Clay"),
	Stone UMETA(DisplayName = "Stone"),
	Bitumen UMETA(DisplayName = "Bitumen"),
	Gold UMETA(DisplayName = "Gold"),
	Silver UMETA(DisplayName = "Silver"),
	Copper UMETA(DisplayName = "Copper"),
	Tin UMETA(DisplayName = "Tin"),

	// Plants and crops
	Trees UMETA(DisplayName = "Trees"),
	Reeds UMETA(DisplayName = "Reeds"),
	Cotton UMETA(DisplayName = "Cotton"),
	Papyrus UMETA(DisplayName = "Papyrus"),
	Flax UMETA(DisplayName = "Flax"),
	Cannabis UMETA(DisplayName = "Cannabis"),
	Wheat UMETA(DisplayName = "Wheat"),
	Barley UMETA(DisplayName = "Barley"),
	Onions UMETA(DisplayName = "Onions"),
	Garlic UMETA(DisplayName = "Garlic"),
	Lentils UMETA(DisplayName = "Lentils"),
	Chickpeas UMETA(DisplayName = "Chickpeas"),
	Grapes UMETA(DisplayName = "Grapes"),
	Olives UMETA(DisplayName = "Olives"),
	Figs UMETA(DisplayName = "Figs"),
	Cucumbers UMETA(DisplayName = "Cucumbers"),

	// Livestock
	Cattle UMETA(DisplayName = "Cattle"),
	Sheep UMETA(DisplayName = "Sheep"),
	Goats UMETA(DisplayName = "Goats"),
	Pigs UMETA(DisplayName = "Pigs"),
	Donkeys UMETA(DisplayName = "Donkeys"),
	Horses UMETA(DisplayName = "Horses"),
	Camels UMETA(DisplayName = "Camels"),
	Bees UMETA(DisplayName = "Bees"),
};
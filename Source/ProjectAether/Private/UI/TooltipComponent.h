#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TooltipComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTAETHER_API UTooltipComponent : public UActorComponent
{
   GENERATED_BODY()

public:
    UTooltipComponent();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Tooltip")
    FString TooltipText;

	UPROPERTY(EditAnywhere, Category = "Tooltip")
	UTooltipComponent *NestedTooltip;
};
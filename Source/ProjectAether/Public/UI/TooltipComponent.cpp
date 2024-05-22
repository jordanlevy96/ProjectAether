#include "CoreMinimal.h"
#include "UI/TooltipComponent.h"

UTooltipComponent::UTooltipComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTooltipComponent::BeginPlay()
{
    Super::BeginPlay();

    
}

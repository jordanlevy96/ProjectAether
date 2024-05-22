#include "UI/TooltipComponent.h"
#include "CoreMinimal.h"

UTooltipComponent::UTooltipComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTooltipComponent::BeginPlay()
{
    Super::BeginPlay();

    
}

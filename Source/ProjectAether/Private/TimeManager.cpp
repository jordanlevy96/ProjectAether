#include "TimeManager.h"
#include "Kismet/GameplayStatics.h"
// TODO: Implement a TimeManager class that handles the management of both the game clock and the simulation clock. This class should:
// - Keep track of the current game date and time (Game Clock).
// - Handle the fast-forward, slow, and paused states of the game time.
// - Process the advancement of the simulation time in fixed steps (Simulation Clock).
// - Trigger any necessary game events based on the simulation increments.
// - Notify other components in the game such as AI manager or event manager when a certain time or date is reached.
//
// Remember to consider unit testing these components as they are critical for the fundamental game mechanics.
UTimeManager::UTimeManager()
{
	TimeScaleBeforePause = 1.0f;
}

void UTimeManager::PauseTime()
{
	TimeScaleBeforePause = UGameplayStatics::GetGlobalTimeDilation(this);
	UGameplayStatics::SetGlobalTimeDilation(this, 0.0f);
}

void UTimeManager::ResumeTime()
{
	UGameplayStatics::SetGlobalTimeDilation(this, TimeScaleBeforePause);
}

void UTimeManager::SetTimeScale(float NewTimeScale)
{
	if (NewTimeScale == 0.0f)
	{
		PauseTime();
	}
	else
	{
		UGameplayStatics::SetGlobalTimeDilation(this, NewTimeScale);
		TimeScaleBeforePause = NewTimeScale;
	}
}

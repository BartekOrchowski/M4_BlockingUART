/*
 * software_timers.c
 *
 *  Created on: Oct 1, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#include "main.h"
#include "software_timers.h"

void SoftTimerEvent(SoftTimer_t *Timer)
{
	if(Timer->TimeToDelay) // If no time to wait - Timer disabled
	{
		if((GetSystemTick() - Timer->LastTick) > Timer->TimeToDelay) // Check if is time to make  action
		{
			Timer->LastTick = GetSystemTick(); // Refill action's timer
			if(Timer->Action)
			{
				Timer->Action(); // Make Action!
			}
		}
	}
}

void SoftTimerAction(SoftTimer_t *Timer, void (*_Action)(void))
{
	Timer->Action = _Action; // Set a new Action
}

void SoftTimerStart(SoftTimer_t *Timer, uint32_t Delay)
{
	if(Delay != 0)
	{
		Timer->TimeToDelay = Delay; // Set Delay
		Timer->LastTick = GetSystemTick(); // Get start Tick

// Choose if you want to make Action with Timer start
//		if(Timer->Action)
//		{
//			Timer->Action();
//		}
	}
}

void SoftTimerStop(SoftTimer_t *Timer)
{
	Timer->TimeToDelay = 0; // No time to wait - Timer disabled
}


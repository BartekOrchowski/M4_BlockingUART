/*
 * main.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */

#include "main.h"
#include "sys_clocks.h"
#include "tester.h"
#include "led.h"
#include "software_timers.h"
#include "lpuart.h"
#include "stdio.h"

SoftTimer_t TimerLD2;
SoftTimer_t TimerLPUART1;

char ReceivedChar;
char ToSend[64];

void TaskLD2(void);
void TaskLPUART1(void);

int main(void)
{
	SystemClockSetup();
	TEST1_Init();
	TEST1_Off();

	LED_LD2_Init();

	LPUART1_Init();

	SoftTimerAction(&TimerLD2, TaskLD2);
	SoftTimerStart(&TimerLD2, 500);

	SoftTimerAction(&TimerLPUART1, TaskLPUART1);
	SoftTimerStart(&TimerLPUART1, 2000);


    /* Loop forever */
	while(1)
	{
		SoftTimerEvent(&TimerLD2);
		SoftTimerEvent(&TimerLPUART1);

		if(!LPUART1_GetChar(&ReceivedChar))
		{
			sprintf(ToSend, "Char Received: %c\n\r", ReceivedChar);
			LPUART1_SendString(ToSend);
		}

	}
}

void TaskLD2(void)
{
	LED_LD2_Toggle();
}

void TaskLPUART1(void)
{
	LPUART1_SendString("Test\n\r");
}




/*
 * software_timers.h
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
#ifndef SOFTWARE_TIMERS_H_
#define SOFTWARE_TIMERS_H_

typedef struct
{
	uint32_t TimeToDelay;
	uint32_t LastTick;
	void (*Action)(void);
} SoftTimer_t;

void SoftTimerEvent(SoftTimer_t *Timer);
void SoftTimerAction(SoftTimer_t *Timer, void (*Action)(void));
void SoftTimerStart(SoftTimer_t *Timer, uint32_t Delay);
void SoftTimerStop(SoftTimer_t *Timer);

#endif /* SOFTWARE_TIMERS_H_ */

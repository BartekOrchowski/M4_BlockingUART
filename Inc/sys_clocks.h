/*
 * sys_clocks.h
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

#ifndef SYS_CLOCKS_H_
#define SYS_CLOCKS_H_

void SystemClockSetup(void);
uint32_t GetSystemTick(void);

// DELAY - WARNING! Blocking
void Delay(uint32_t Delay_ms);

#endif /* SYS_CLOCKS_H_ */

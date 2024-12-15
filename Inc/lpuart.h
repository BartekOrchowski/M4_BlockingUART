/*
 * lpuart.h
 *
 *  Created on: Oct 15, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#ifndef LPUART_H_
#define LPUART_H_

void LPUART1_Init(void);

uint8_t LPUART1_GetChar(char *ch);
void LPUART1_SendString(char *str);

#endif /* LPUART_H_ */

/*
 * tester.c
 *
 *  Created on: Oct 19, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#include "main.h"
#include "tester.h"

void TEST1_Init(void)
{
	// Test Pin 1 on PC8
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	GPIOC->MODER &= ~(GPIO_MODER_MODE8_1);
}

__attribute__((always_inline)) inline void TEST1_On(void)
{
	GPIOC->BSRR = GPIO_BSRR_BS8;
}

__attribute__((always_inline)) inline void TEST1_Off(void)
{
	GPIOC->BSRR = GPIO_BSRR_BR8;
}

__attribute__((always_inline)) inline void TEST1_Toggle(void)
{
	GPIOC->ODR ^= GPIO_ODR_OD8;
}

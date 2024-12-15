/*
 * led.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#include "main.h"
#include "led.h"


// 1 - On
// 0 - Off

void LED_LD2_Init(void)
{
	// LD2 on PA5
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);

//	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5); // After reset is ok

//	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5);

//	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);
}

__attribute__((always_inline)) inline void LED_LD2_On(void)
{
//	GPIOA->ODR |= GPIO_ODR_OD5;
	GPIOA->BSRR = GPIO_BSRR_BS5;
}

__attribute__((always_inline)) inline void LED_LD2_Off(void)
{
//	GPIOA->ODR &= ~(GPIO_ODR_OD5);
	GPIOA->BSRR = GPIO_BSRR_BR5;
}

__attribute__((always_inline)) inline void LED_LD2_Toggle(void)
{
	GPIOA->ODR ^= GPIO_ODR_OD5;
}


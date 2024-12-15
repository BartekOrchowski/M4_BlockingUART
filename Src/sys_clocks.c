/*
 * sys_clocks.c
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

__IO uint32_t Tick;

// Reset Configuration
// Start HSI16
// HSI16 as SYSCLK = 16 MHz
// HPRE /1 = 16 MHZ HCLK
// APB1 PRE /1 = 16 Mhz PCLK1
// APB2 PRE /1 = 16 Mhz PCLK2
// 1 Wait State
// Vcore Range 1 normal mode

void SystemClockHSE24(void)
{
// HSE 24 MHz select
	// HSE On
	RCC->CR |= RCC_CR_HSEON;

	// Wait for HSE
	while(!(RCC->CR & RCC_CR_HSERDY));

	// Change switch
	RCC->CFGR |= RCC_CFGR_SW_1;
	RCC->CFGR &= ~(RCC_CFGR_SW_0);

	// Wait for switch
	while(!(RCC->CFGR & RCC_CFGR_SWS_1) && (RCC->CFGR & RCC_CFGR_SWS_0));
}

void SystemClockPLL48(void)
{
// Medium Speed 48 MHz, PLL and HSE
// System Clock Mux to PLL
// PLL Clock Mux
// PLL ON and set

// HSE 24 MHz select
	// HSE On
	RCC->CR |= RCC_CR_HSEON;

	// Wait for HSE
	while(!(RCC->CR & RCC_CR_HSERDY));

// HSE as PLL Source
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLSRC);

// Dividers for 48M
	// PLLM Divider /2
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_0;
	// PLLN Multiplier *8 -  default is 0b0010000
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |= (8 << RCC_PLLCFGR_PLLN_Pos);
	// PLLR Divider /2
	// It's default

// PLL Enable
	RCC->CR |= RCC_CR_PLLON;
	// Wait for PLL
	while(!(RCC->CR & RCC_CR_PLLRDY));

// PLL Output R Enable
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;

// Change switch to PLL
	RCC->CFGR |= RCC_CFGR_SW_1;
	RCC->CFGR |= RCC_CFGR_SW_0;

	// Wait for switch
	while(!((RCC->CFGR & RCC_CFGR_SWS_1) && (RCC->CFGR & RCC_CFGR_SWS_0)));
}

void SystemClockPLL100(void)
{
// 100 MHz, PLL and HSE
// System Clock Mux to PLL
// PLL Clock Mux
// PLL ON and set

// HSE 24 MHz select
	// HSE On
	RCC->CR |= RCC_CR_HSEON;

	// Wait for HSE
	while(!(RCC->CR & RCC_CR_HSERDY));

// HSE as PLL Source
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLSRC);

	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	FLASH->ACR |= FLASH_ACR_LATENCY_3WS;
	while(!(FLASH->ACR & FLASH_ACR_LATENCY_3WS));

// Dividers for 100M
	// PLLM Divider /3
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_1;
	// PLLN Multiplier *25 -  default is 0b0010000
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |= (25 << RCC_PLLCFGR_PLLN_Pos);
	// PLLR Divider /2
	// It's default

// PLL Enable
	RCC->CR |= RCC_CR_PLLON;
	// Wait for PLL
	while(!(RCC->CR & RCC_CR_PLLRDY));

// PLL Output R Enable
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;

// Change switch to PLL
	RCC->CFGR |= RCC_CFGR_SW_1;
	RCC->CFGR |= RCC_CFGR_SW_0;

	// Wait for switch
	while(!((RCC->CFGR & RCC_CFGR_SWS_1) && (RCC->CFGR & RCC_CFGR_SWS_0)));
}

void SystemClockPLL170(void)
{
// 170 MHz, PLL and HSE
// System Clock Mux to PLL
// PLL Clock Mux
// PLL ON and set

// HSE 24 MHz select
	// HSE On
	RCC->CR |= RCC_CR_HSEON;

	// Wait for HSE
	while(!(RCC->CR & RCC_CR_HSERDY));

	RCC->CFGR |= RCC_CFGR_HPRE_DIV2;

	PWR->CR5 &= ~(PWR_CR5_R1MODE);

	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	FLASH->ACR |= FLASH_ACR_LATENCY_5WS;
	while(!(FLASH->ACR & FLASH_ACR_LATENCY_5WS));

// HSE as PLL Source
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLSRC);

// Dividers for 170M
	// PLLM Divider /2
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM);
	RCC->PLLCFGR |= (6-1) << RCC_PLLCFGR_PLLM_Pos;
	// PLLN Multiplier *85 -  default is 0b0010000
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |= (85 << RCC_PLLCFGR_PLLN_Pos);
	// PLLR Divider /2
	// It's default

// PLL Enable
	RCC->CR |= RCC_CR_PLLON;
	// Wait for PLL
	while(!(RCC->CR & RCC_CR_PLLRDY));

// PLL Output R Enable
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;

// Change switch to PLL
	RCC->CFGR |= RCC_CFGR_SW_1;
	RCC->CFGR |= RCC_CFGR_SW_0;

	// Wait for switch
	while(!((RCC->CFGR & RCC_CFGR_SWS_1) && (RCC->CFGR & RCC_CFGR_SWS_0)));

	RCC->CFGR &= ~(RCC_CFGR_HPRE);
}
void SystemClockSetup(void)
{
//	SystemClockHSE24();
	SystemClockPLL48();
//	SystemClockPLL100();
//	SystemClockPLL170();

	SysTick_Config(48000000 / 1000);
}

// SYSTICK TIMER
void SysTick_Handler(void)
{
	Tick++; // Increase system timer
}

uint32_t GetSystemTick(void)
{
	return Tick;
}

// DELAY - WARNING! Blocking
void Delay(uint32_t Delay_ms)
{
	uint32_t StartTime = Tick;

	while(Tick < (StartTime + Delay_ms))
	{
		// Just wait
	}
}


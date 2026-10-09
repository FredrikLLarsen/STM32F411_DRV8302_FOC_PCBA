/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : SWV "Hello" + ADC read on PA3 (ADC1_IN3)
  ******************************************************************************
  * @attention
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  * This software is provided AS-IS.
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

/* Function prototypes -------------------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

/* ========================= ADC HELPER ===================================== */
static uint16_t ADC1_Read_PA3_Once(void)
{
  HAL_ADC_Start(&hadc1);
  HAL_ADC_PollForConversion(&hadc1, 10);
  uint16_t val = (uint16_t)HAL_ADC_GetValue(&hadc1);
  HAL_ADC_Stop(&hadc1);
  return val;
}

/* ========================================================================== */
/*                                      MAIN                                  */
/* ========================================================================== */

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  /* printf over SWV: make stdout unbuffered (so data appears immediately) */
  setvbuf(stdout, NULL, _IONBF, 0);

  MX_GPIO_Init();
  MX_ADC1_Init();

  while (1) {
    ITM_SendChar('A');           // raw ITM write
    for (volatile int i=0; i<10000; ++i) {}  // tiny delay
  }

}

/* ========================================================================== */
/*                           System / Peripheral Init                         */
/* ========================================================================== */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* HSE + PLL to 72 MHz SYSCLK */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) Error_Handler();

  RCC_ClkInitStruct.ClockType =
      RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) Error_Handler();
}

static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* PA3 -> ADC1_IN3 (analog) */
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin  = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

static void MX_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  hadc1.Instance                      = ADC1;
  hadc1.Init.ClockPrescaler           = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution               = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode             = DISABLE;
  hadc1.Init.ContinuousConvMode       = DISABLE;   /* one-shot */
  hadc1.Init.DiscontinuousConvMode    = DISABLE;
  hadc1.Init.ExternalTrigConvEdge     = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv         = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign                = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion          = 1;
  hadc1.Init.DMAContinuousRequests    = DISABLE;
  hadc1.Init.EOCSelection             = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK) Error_Handler();

  /* Regular channel: PA3 -> ADC1_IN3 */
  sConfig.Channel      = ADC_CHANNEL_3;
  sConfig.Rank         = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) Error_Handler();
}

void Error_Handler(void)
{
  __disable_irq();
  while (1) { }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  (void)file; (void)line;
}
#endif

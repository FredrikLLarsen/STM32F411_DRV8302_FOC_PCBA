/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define nOCTW___GPIO_INPUT_Pin GPIO_PIN_13
#define nOCTW___GPIO_INPUT_GPIO_Port GPIOC
#define AS5600_PWM_GPIO_INPUT_Pin GPIO_PIN_14
#define AS5600_PWM_GPIO_INPUT_GPIO_Port GPIOC
#define QUAD_A_TIM2CH1_Pin GPIO_PIN_0
#define QUAD_A_TIM2CH1_GPIO_Port GPIOA
#define QUAD_B_TIM2CH2_Pin GPIO_PIN_1
#define QUAD_B_TIM2CH2_GPIO_Port GPIOA
#define A_SENSE_ADC1_IN2_Pin GPIO_PIN_2
#define A_SENSE_ADC1_IN2_GPIO_Port GPIOA
#define MOS1_NTC_Pin GPIO_PIN_3
#define MOS1_NTC_GPIO_Port GPIOA
#define B_SENSE_ADC1_IN4_Pin GPIO_PIN_4
#define B_SENSE_ADC1_IN4_GPIO_Port GPIOA
#define C_Sense_ADC1_IN6_Pin GPIO_PIN_6
#define C_Sense_ADC1_IN6_GPIO_Port GPIOA
#define PVDDSENSE_Pin GPIO_PIN_7
#define PVDDSENSE_GPIO_Port GPIOA
#define HALLZ_TIM3CH3_Pin GPIO_PIN_0
#define HALLZ_TIM3CH3_GPIO_Port GPIOB
#define MOT_NTC_1_Pin GPIO_PIN_1
#define MOT_NTC_1_GPIO_Port GPIOB
#define nFault___GPIO_INPUT_Pin GPIO_PIN_2
#define nFault___GPIO_INPUT_GPIO_Port GPIOB
#define INL_A_TIM1_CH1N_Pin GPIO_PIN_13
#define INL_A_TIM1_CH1N_GPIO_Port GPIOB
#define INL_B_TIM1_CH2N_Pin GPIO_PIN_14
#define INL_B_TIM1_CH2N_GPIO_Port GPIOB
#define INL_C_TIM1_CH3N_Pin GPIO_PIN_15
#define INL_C_TIM1_CH3N_GPIO_Port GPIOB
#define INH_A_TIM1_CH1_Pin GPIO_PIN_8
#define INH_A_TIM1_CH1_GPIO_Port GPIOA
#define INH_B_TIM1_CH2_Pin GPIO_PIN_9
#define INH_B_TIM1_CH2_GPIO_Port GPIOA
#define INH_C_TIM1_CH3_Pin GPIO_PIN_10
#define INH_C_TIM1_CH3_GPIO_Port GPIOA
#define QUAD_Z_EXTI15_Pin GPIO_PIN_15
#define QUAD_Z_EXTI15_GPIO_Port GPIOA
#define HALL_A_TIM3CH1_Pin GPIO_PIN_4
#define HALL_A_TIM3CH1_GPIO_Port GPIOB
#define HALL_B_TIM3CH2_Pin GPIO_PIN_5
#define HALL_B_TIM3CH2_GPIO_Port GPIOB
#define DC_CAL_GPIO_OUTPUT_Pin GPIO_PIN_8
#define DC_CAL_GPIO_OUTPUT_GPIO_Port GPIOB
#define DRV_M_PWM_GPIO_OUTPUT_Pin GPIO_PIN_9
#define DRV_M_PWM_GPIO_OUTPUT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

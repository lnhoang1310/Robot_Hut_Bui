/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define Relay_Hut_Pin GPIO_PIN_13
#define Relay_Hut_GPIO_Port GPIOC
#define Relay_Quet_Pin GPIO_PIN_14
#define Relay_Quet_GPIO_Port GPIOC
#define Encoder_B_Motor1_Pin GPIO_PIN_0
#define Encoder_B_Motor1_GPIO_Port GPIOA
#define Encoder_A_Motor1_Pin GPIO_PIN_1
#define Encoder_A_Motor1_GPIO_Port GPIOA
#define Motor_Left_IN1_Pin GPIO_PIN_4
#define Motor_Left_IN1_GPIO_Port GPIOA
#define Motor_Left_IN2_Pin GPIO_PIN_5
#define Motor_Left_IN2_GPIO_Port GPIOA
#define Motor_Right_IN1_Pin GPIO_PIN_6
#define Motor_Right_IN1_GPIO_Port GPIOA
#define VL53L0X_Right_XHSUT_Pin GPIO_PIN_7
#define VL53L0X_Right_XHSUT_GPIO_Port GPIOA
#define VL53L0X_Right_SCL_Pin GPIO_PIN_0
#define VL53L0X_Right_SCL_GPIO_Port GPIOB
#define VL53L0X_Right_SDA_Pin GPIO_PIN_1
#define VL53L0X_Right_SDA_GPIO_Port GPIOB
#define VL53L0X_Left_XHSUT_Pin GPIO_PIN_12
#define VL53L0X_Left_XHSUT_GPIO_Port GPIOB
#define VL53L0X_Left_SCL_Pin GPIO_PIN_13
#define VL53L0X_Left_SCL_GPIO_Port GPIOB
#define VL53L0X_Left_SDA_Pin GPIO_PIN_14
#define VL53L0X_Left_SDA_GPIO_Port GPIOB
#define PWM_Motor_Left_Pin GPIO_PIN_8
#define PWM_Motor_Left_GPIO_Port GPIOA
#define PWM_Motor_Right_Pin GPIO_PIN_9
#define PWM_Motor_Right_GPIO_Port GPIOA
#define Motor_Right_IN2_Pin GPIO_PIN_11
#define Motor_Right_IN2_GPIO_Port GPIOA
#define VL53L0X_Front_XHSUT_Pin GPIO_PIN_3
#define VL53L0X_Front_XHSUT_GPIO_Port GPIOB
#define VL53L0X_Front_SCL_Pin GPIO_PIN_4
#define VL53L0X_Front_SCL_GPIO_Port GPIOB
#define VL53L0X_Front_SDA_Pin GPIO_PIN_5
#define VL53L0X_Front_SDA_GPIO_Port GPIOB
#define Encoder_B_Motor2_Pin GPIO_PIN_6
#define Encoder_B_Motor2_GPIO_Port GPIOB
#define Encoder_A_Motor2_Pin GPIO_PIN_7
#define Encoder_A_Motor2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

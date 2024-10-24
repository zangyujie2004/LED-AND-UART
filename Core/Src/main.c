/* USER CODE BEGIN Header */
/**
  *******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  *******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  *******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>

/* Private variables ---------------------------------------------------------*/
uint8_t rx_buff[8]; // 接收缓冲区

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM6_Init();
  MX_UART8_Init();
  MX_UART7_Init();
  MX_UART5_Init();

  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  HAL_TIM_Base_Start(&htim1);
  HAL_UART_Receive_IT(&huart8, rx_buff, sizeof(rx_buff)); // 开始接收数据

  while (1)
  {
    // 主循环可以执行其他任务，不需要在这里进行 UART 接收和发送
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
  if (huart->Instance == huart8.Instance) {
    // 发送接收到的数据
    HAL_UART_Transmit_IT(&huart8, rx_buff, sizeof(rx_buff));

    // 重新启动接收
    HAL_UART_Receive_IT(&huart8, rx_buff, sizeof(rx_buff));
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void) {
  // 时钟配置代码...
}

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

void Error_Handler(void) {
  // 错误处理代码...
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
  // 断言失败处理...
}
#endif /* USE_FULL_ASSERT */

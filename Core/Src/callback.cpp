//
// Created by Administrator on 24-10-2.
//

#include "main.h"
#include "usart.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == KEY_Pin) {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
    }
}



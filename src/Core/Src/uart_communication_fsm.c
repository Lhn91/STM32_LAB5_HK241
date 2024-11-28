/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 27, 2024
 *      Author: 84859
 */
#include "uart_communication_fsm.h"

void uart_communication_fsm() {

    char response[30];

    switch (state) {
        case RESPONDING:
            if (command_flag == 1) { // Lệnh !RST#
                command_flag = 0; // Xóa cờ
                //sprintf(response, "!ADC=%lu#", ADC_value);
                HAL_UART_Transmit(&huart2, (uint8_t *)response, sprintf (response , "!ADC=%lu\n#", ADC_value ), HAL_MAX_DELAY);
                timeout_start = HAL_GetTick();
                state = WAIT_ACK;
            }

            if (command_flag == 2){
            	state = IDLE;
            }
            break;

        case WAIT_ACK:
            if (HAL_GetTick() - timeout_start > 3000) { // Hết thời gian chờ
                HAL_UART_Transmit(&huart2, (uint8_t *)response, sprintf (response , "!ADC=%lu\n#", ADC_value ), HAL_MAX_DELAY);
                timeout_start = HAL_GetTick();
            }
            if(buffer_flag == 1){
            	state = IDLE;
            }
            break;
    }
}



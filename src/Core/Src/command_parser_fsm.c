/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 27, 2024
 *      Author: 84859
 */
#include "command_parser_fsm.h"
uint8_t validate_command(uint8_t *buffer) {
    if (buffer[0] == '!' && buffer[strlen((char *)buffer) - 1] == '#') {
        if (strncmp((char *)&buffer[1], "RST", strlen("RST")) == 0) {
            return 1; // Lệnh Reset hợp lệ
        } else if (strncmp((char *)&buffer[1], "OK", strlen("OK")) == 0) {
            return 2; // Lệnh OK hợp lệ
        }
    }
    return 0; // Lệnh không hợp lệ
}

void command_parser_fsm() {
    switch (state) {
        case IDLE:
            if (temp == '!') { // Ký tự bắt đầu lệnh
            	command_flag = 1;
                state = RECEIVING;
            }
            break;

        case RECEIVING:
        	if(temp != '!'){
        		//HAL_UART_Transmit(&huart2, (uint8_t *)"Hello UART\n", 11, 1000);
        		command_flag = 0;
        		break;
        	}
        	command_flag = 0;
			  // Ký tự kết thúc lệnh
					if(temp == '#'){
						buffer[index_buffer] = '\0';
						if (validate_command(buffer)) { // Kiểm tra lệnh hợp lệ
							command_flag = validate_command(buffer); // Đặt cờ báo hiệu có lệnh hợp lệ
							state = RESPONDING;
						}
					 }

            break;
    }
    HAL_UART_Transmit(&huart2, &temp, 1, 100);
    HAL_UART_Transmit(&huart2, &buffer[0], 1, 100);
    HAL_UART_Transmit(&huart2, &buffer[1], 1, 100);
    HAL_UART_Transmit(&huart2, &buffer[2], 1, 100);
    HAL_UART_Transmit(&huart2, &buffer[3], 1, 100);
}
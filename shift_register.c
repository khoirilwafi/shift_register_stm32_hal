/*
 * shift_register.c
 *
 * Created : 08/10/2019
 * Author  : Muhammad Khoiril Wafi
 * Company : Teknik Elektro Diponegoro University
 *
 */

#include <stdio.h>
#include "shift_register.h"

Shift_HandleTypeDef hshift;

void Register_create(Shift_PortType clk_port, Shift_PinType clk_pin, Shift_PortType data_port, Shift_PinType data_pin, Shift_PortType latch_port, Shift_PinType latch_pin)
{

	hshift.clk_port = clk_port;
	hshift.clk_pin = clk_pin;
	hshift.data_port = data_port;
	hshift.data_pin = data_pin;
	hshift.latch_port = latch_port;
	hshift.latch_pin = latch_pin;
}

void Register_send(uint8_t data[], uint32_t length)
{
	for(uint32_t index=0; index<length; index++)
	{
		uint8_t buffer = data[index];

		for(uint8_t i=0; i<8; i++)
		{
			HAL_GPIO_WritePin(hshift.data_port, hshift.data_pin, buffer & 0x80);
			HAL_GPIO_WritePin(hshift.clk_port, hshift.clk_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(hshift.clk_port, hshift.clk_pin, GPIO_PIN_RESET);
			buffer = buffer << 1;
		}
	}

	HAL_GPIO_WritePin(hshift.latch_port, hshift.latch_pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(hshift.latch_port, hshift.latch_pin, GPIO_PIN_RESET);
}

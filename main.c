#include "lcd-wh1602-04.h"
#include "stm32f10x_gpio.h"
#include <stdio.h>

char buf[17];

int main(void) {

	lcd44780_init_pins();
	lcd44780_init();

	GPIO_InitTypeDef B1;
	GPIO_Init(GPIOA, &B1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	B1.GPIO_Pin = GPIO_Pin_0;
	B1.GPIO_Mode = GPIO_Mode_IPU;
	B1.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);


	while (1) {


		lcd44780_SetLCDPosition(4, 0);
		snprintf(buf, sizeof(buf), "PRESS");
		lcd44780_ShowStr(buf);

		lcd44780_SetLCDPosition(3, 1);
		snprintf(buf, sizeof(buf), "BUTTON B1");
		lcd44780_ShowStr(buf);

		lcd44780_delay(200000);
		lcd44780_ClearLCD();


		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)
		{

		lcd44780_SetLCDPosition(0, 0);
		snprintf(buf, sizeof(buf), "BUTTON");
		lcd44780_ShowStr(buf);

		lcd44780_SetLCDPosition(0, 1);
		snprintf(buf, sizeof(buf), "PRESSED");
		lcd44780_ShowStr(buf);

		lcd44780_delay(200000);
		lcd44780_ClearLCD();
		lcd44780_delay(300000);

	}
}
}

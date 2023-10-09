/*
 * main.c
 *
 * Created: 10/9/2023 4:12:19 PM
 *  Author: youmna abbas
 */ 

/* Section : Includes */
#include "main1.h"

/* Section : global variables */
pin_config_t led_1 = {
	.pin = GPIO_PIN0,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};

pin_config_t led_2 = {
	.pin = GPIO_PIN1,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};

pin_config_t led_3 = {
	.pin = GPIO_PIN2,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};

pin_config_t led_4 = {
	.pin = GPIO_PIN3,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};

pin_config_t led_5 = {
	.pin = GPIO_PIN4,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};

pin_config_t led_6 = {
	.pin = GPIO_PIN5,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};

int main(void)
{
	main_initialize();
	
	while(1)
	{
		gpio_pin_toggle_logic(&led_1);
		gpio_pin_toggle_logic(&led_2);
		gpio_pin_toggle_logic(&led_3);
		gpio_pin_toggle_logic(&led_4);
		gpio_pin_toggle_logic(&led_5);
		gpio_pin_toggle_logic(&led_6);
		
		_delay_ms(500);
	}
}


void main_initialize (void){
	gpio_pin_direction_initialize(&led_1);
	gpio_pin_direction_initialize(&led_2);
	gpio_pin_direction_initialize(&led_3);
	gpio_pin_direction_initialize(&led_4);
	gpio_pin_direction_initialize(&led_5);
	gpio_pin_direction_initialize(&led_6);
}
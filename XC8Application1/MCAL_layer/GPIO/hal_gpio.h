/*
 * hal_gpio.h
 *
 * Created: 10/9/2023 4:24:13 PM
 *  Author: youmna abbas
 */ 


#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_


/*section : includes */
#include "MCAL_layer/std/compiler.h"
#include "MCAL_layer/device_config.h"
#include "MCAL_layer/std/mcal_std_types.h"
#include "avr/io.h"
#include "avr/iotn85.h"
#include "MCAL_layer/GPIO/hal_gpio_cfg.h"

/*section : macro declarations */
#define BIT_MASK (uint8)1

#define PIN_MAX_NUMBER (uint8)6

#define PORT_MASK 0xFF
/*section : macro functions declarations */
#define SET_BIT(REG,BIT_POSN)                 (REG |= BIT_MASK << BIT_POSN)
#define CLEAR_BIT(REG,BIT_POSN)               (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)              (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)                ((REG >> BIT_POSN)&BIT_MASK)

/*section : data types declarations */
typedef enum{
	GPIO_LOW = 0,
	GPIO_HIGH
}logic_t;

typedef enum{
	GPIO_INPUT = 0,
	GPIO_OUTPUT
}direction_t;

typedef enum{
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	
}pin_index_t;

typedef struct{
	uint8 reserved  : 3;
	uint8 pin       : 3;
	uint8 direction : 1;
	uint8 logic     : 1;
}pin_config_t;

/*section : functions declarations */
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_cfg);
Std_ReturnType gpio_pin_get_direction_st(const pin_config_t *pin_cfg,direction_t *direction_st);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_cfg, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_cfg,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_cfg);
Std_ReturnType gpio_pin_initialize(const pin_config_t *pin_cfg);

Std_ReturnType gpio_port_direction_initialize(uint8 direction);
Std_ReturnType gpio_port_get_direction_st( uint8 *direction_st);
Std_ReturnType gpio_port_write_logic(uint8 logic);
Std_ReturnType gpio_port_read_logic(uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(void);


#endif /* HAL_GPIO_H_ */
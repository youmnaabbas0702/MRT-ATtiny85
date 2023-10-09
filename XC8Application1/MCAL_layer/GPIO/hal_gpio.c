/*
 * hal_gpio.c
 *
 * Created: 10/9/2023 4:23:51 PM
 *  Author: youmna abbas
 */ 

/* Section : Includes */
#include "GPIO/hal_gpio.h"

/*section : functions definitions */
#if PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_cfg){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_cfg)||(pin_cfg->pin > PIN_MAX_NUMBER-1)){
            ret = E_NOT_OK; 
        }
        else{
        switch(pin_cfg->direction){
			    case GPIO_INPUT :
                    SET_BIT(DDRB, pin_cfg->pin); 
                    break;
			
                case GPIO_OUTPUT :
                    CLEAR_BIT(DDRB, pin_cfg->pin);
                    break;
                
                default :  ret = E_NOT_OK;   
        }
}
		return ret;
}
#endif

#if PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_st(const pin_config_t *pin_cfg,direction_t *direction_st){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_cfg)||(NULL == direction_st)||(pin_cfg->pin > PIN_MAX_NUMBER-1)){
            ret = E_NOT_OK; 
        }
        else{
        *direction_st = READ_BIT(DDRB, pin_cfg->pin);
        }
    return ret;
}
#endif

#if PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_cfg, logic_t logic){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_cfg)||(pin_cfg->pin > PIN_MAX_NUMBER-1)){
            ret = E_NOT_OK; 
        }
    switch(logic){
        case GPIO_LOW :
           CLEAR_BIT(PORTB, pin_cfg->pin);
            break;
        case GPIO_HIGH :
           SET_BIT(PORTB, pin_cfg->pin);
            break;
        default : ret = E_NOT_OK;
    }
    return ret; 
}
#endif


#if PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_cfg,logic_t *logic){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_cfg)||(NULL == logic)||(pin_cfg->pin > PIN_MAX_NUMBER-1)){
            ret = E_NOT_OK; 
        }
        else{
        *logic = READ_BIT(PINB, pin_cfg->pin);
        }
    return ret;
}
#endif

#if PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_cfg){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_cfg)||(pin_cfg->pin > PIN_MAX_NUMBER-1)){
            ret = E_NOT_OK; 
        }
        else{
        TOGGLE_BIT(PORTB, pin_cfg->pin);
        }
    return ret;
}
#endif

#if PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t *pin_cfg){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_cfg)||(pin_cfg->pin > PIN_MAX_NUMBER-1)){
            ret = E_NOT_OK; 
        }
        else{
        ret = gpio_pin_direction_initialize(pin_cfg);
        ret = gpio_pin_write_logic(pin_cfg, pin_cfg->logic);
        }
    return ret;
}
#endif

#if PORT_CONFIGURATIONS==CONFIG_ENABLE

Std_ReturnType gpio_port_direction_initialize(uint8 direction){
    Std_ReturnType ret = E_OK;
        DDRB = direction; 
    
    return ret;
}
#endif

#if PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_st(uint8 *direction_st){
    Std_ReturnType ret = E_OK;
    if(NULL == direction_st){
            ret = E_NOT_OK; 
    }
    else{
       *direction_st = DDRB; 
    }
	return ret;
    
}
#endif

#if PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(uint8 logic){
    Std_ReturnType ret = E_OK;
        PORTB = logic;
    return ret;
}
#endif

#if PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(uint8 *logic){
    Std_ReturnType ret = E_OK; 
    if(NULL == logic){
            ret = E_NOT_OK; 
        }
        else{
        *logic = PINB;
        }
    return ret;
}
#endif

#if PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(void){
    Std_ReturnType ret = E_OK;  
        PORTB ^= PORT_MASK;
    return ret;
}
#endif

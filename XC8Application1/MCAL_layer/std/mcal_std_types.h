/*
 * mcal_std_types.h
 *
 * Created: 10/9/2023 4:28:34 PM
 *  Author: youmna abbas
 */ 


#ifndef MCAL_STD_TYPES_H_
#define MCAL_STD_TYPES_H_


/*section : includes */
#include "MCAL_layer/std/compiler.h"
#include "MCAL_layer/std/std_libraries.h"
/*section : data types declarations */

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;

/*section : macro declarations */
#define STD_HIGH    0x01
#define STD_LOW     0x00

#define STD_ACTIVE  0x01
#define STD_IDLE    0x00

#define STD_ON      0x01
#define STD_OFF     0x00

#define E_OK           (Std_ReturnType)0x01
#define E_NOT_OK       (Std_ReturnType)0x00

/*section : macro functions declarations */

/*section : functions declarations */


#endif /* MCAL_STD_TYPES_H_ */
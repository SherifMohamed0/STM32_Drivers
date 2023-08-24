/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 18 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SS_interface.h"
#include "SS_private.h"
#include "SS_config.h"



void HSS_voidInit(void)
{
	MGPIO_voidSetPinDirection(SS_COMMON_PIN , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PINA 	    , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PINB       , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PINC 	    , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PIND       , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PINE       , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PINF       , OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(SS_PING       , OUTPUT_2MHZ_PP);


}

void HSS_voidDisplay(u8 Copy_u8Value)
{
	if(Copy_u8Value <= 9)
	{
#if(TYPE_OF_CONNECTION == COMMON_ANODE)
		{
			MGPIO_voidSetPinValue(SS_COMMON_PIN , GPIO_HIGH);
			switch(Copy_u8Value)
			{
			case 0:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PING       , GPIO_HIGH);
				break;
			case 1:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC 	    , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PING       , GPIO_HIGH);
				break;
			case 2:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW);
				break;
			case 3:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW);
				break;
			case 4:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW );
				break;
			case 5:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW );
				break;
			case 6:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW );
				break;
			case 7:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PING       , GPIO_HIGH);
				break;
			case 8:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW );
				break;
			case 9:
				MGPIO_voidSetPinValue(SS_PINA 	    , GPIO_LOW);
				MGPIO_voidSetPinValue(SS_PINB       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINC	    , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PIND       , GPIO_HIGH);
				MGPIO_voidSetPinValue(SS_PINE       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PINF       , GPIO_LOW );
				MGPIO_voidSetPinValue(SS_PING       , GPIO_LOW );
				break;
			}
		}
#elif (TYPE_OF_CONNECTION == COMMON_CATHODE)
		{
			void MGPIO_voidSetPinValue(SS_COMMON_PIN , GPIO_LOW);
		}
#endif
	}
	else 
	{
		/* Return Error*/
	}
}

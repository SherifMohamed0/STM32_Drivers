/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 16 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit ,u8 *Copy_u8DataToReceive)
{
	/* Clear for slave select chip*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	/*send data*/
	MSPI1 ->DR = Copy_u8DataToTransmit;
	
	/* Wait for flag to finish*/
	while(GET_BIT(MSPI1->SR ,7) == 1){}
	
	/* Return the data received  */
	*Copy_u8DataToReceive = MSPI1 -> DR;
	/* SET slave pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}
/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 4 October 2020                                 */
/* Version  : V01                                            */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "EXTI0_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


volatile u8  u8StartFlag      =  0;
volatile u32 u32FrameData[50] = {0};
volatile u8  u8EdgeCounter    =  0;
volatile u8  *Ptr_Data        =  0;

 /* Define Callback Global Variable */
volatile void (*IR_Ptr) (void);


void HIR_voidInit(u8 *Copy_data ,void (*ptr)(void))
{
	/* Set the receiver pin as Input pin */
	MGPIO_voidSetPinDirection(IR_RECIEVER_PIN , INPUT_FLOATING);
	
	/* Initialize EXTI0 and Set the Callback */
	MEXTI_voidInit();
	MEXTI_voidSetCallBack(voidGetFrame);
	
	IR_Ptr   = ptr();
	Ptr_Data = Copy_data;
}

static void voidGetFrame(void)
{
	if(u8StartFlag == 0)
	{
		MSTK_voidSetIntervalSingle(500000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTL_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(500000,voidTakeAction);
		u8EdgeCounter++;
	}
}

static void voidTakeAction(void)
{
	u8 i;
	(*Ptr_Data) = 0;

	for(i=0 ; i < 8 ; i++)
	{
		if( (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 2300))
		{
			SET_BIT((*Ptr_Data) , i);
		}

		else
		{
			CLR_BIT((*Ptr_Data) , i);
		}
	}

	IR_Ptr();
	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}
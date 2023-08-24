/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 23 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Callback Global Variable */
void (*MSTK_CallBack) (void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	/* Disable interrupt
	   Disable  STK*/
	STK_CTRL = 0x00000000;

	/* Choose the CLK Source AHB or AHB_DIV_8 */
#if(CLk_SOURCE == 0)
	{   
		/* CLk_SOURCE = AHB */
		SET_BIT(STK_CTRL , 2);
	}

#elif(CLk_SOURCE == 1)
	{
		/* CLk_SOURCE = AHB/8 */
		CLR_BIT(STK_CTRL , 2);
	}

#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Set the number of Tick wanted */
	STK_LOAD = Copy_u32Ticks;

	/* Enable SysTick */
	SET_BIT(STK_CTRL , 0);

	/* Wait until the timer finish */
	while( (GET_BIT(STK_CTRL , 16)) == 0){}

	/* Stop Timer */
	CLR_BIT(STK_CTRL , 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}

void MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , void(*Copy_Ptr)(void))
{
	/* Set the number of Tick wanted */
	STK_LOAD = Copy_u32Ticks;

	/* Enable SysTick */
	SET_BIT(STK_CTRL , 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_Ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

	/*Enable Interrupts */
	SET_BIT(STK_CTRL , 1);

}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void(*Copy_Ptr)(void))
{	
	/* Set the number of Tick wanted */
	STK_LOAD = Copy_u32Ticks;

	/* Enable SysTick */
	SET_BIT(STK_CTRL , 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_Ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;

	/*Enable Interrupts */
	SET_BIT(STK_CTRL , 1);

}


void MTSK_voidStopInterval(void)
{
	/* Stop Timer */
	CLR_BIT(STK_CTRL , 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}

u32  MSTL_u32GetElapsedTime(void)
{
	return (STK_LOAD - STK_VAL);
}

u32  MSTL_u32GetRemainingTime(void)
{
	return (STK_VAL);
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK_CTRL, 1);

		/* Stop Timer */
		CLR_BIT(STK_CTRL , 0);
		STK_LOAD = 0;
		STK_VAL  = 0;
	}

	/* Callback notification */
	MSTK_CallBack();

	/* Clear interrupt flag by reading it */
	Local_u8Temporary = GET_BIT(STK_CTRL,16);
}

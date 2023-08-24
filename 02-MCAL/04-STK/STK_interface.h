/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 23 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

 /* Functions Definitions */

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , void(*Copy_Ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void(*Copy_Ptr)(void));
void MTSK_voidStopInterval(void);
u32  MSTL_u32GetElapsedTime(void);
u32  MSTL_u32GetRemainingTime(void);

#endif

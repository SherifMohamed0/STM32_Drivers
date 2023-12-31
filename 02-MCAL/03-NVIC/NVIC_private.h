/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 19 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* NVIC Base ADDRESS*/
#define BASE_ADDRESS   0xE000E100

/* NVIC Register Definitions */
#define NVIC_ISER0  		*((volatile u32 *)(BASE_ADDRESS+0x000))
#define NVIC_ISER1  		*((volatile u32 *)(BASE_ADDRESS+0x004))

#define NVIC_ICER0  		*((volatile u32 *)(BASE_ADDRESS+0x080))
#define NVIC_ICER1  		*((volatile u32 *)(BASE_ADDRESS+0x084))

#define NVIC_ISPR0  		*((volatile u32 *)(BASE_ADDRESS+0x100))
#define NVIC_ISPR1  		*((volatile u32 *)(BASE_ADDRESS+0x104))

#define NVIC_ICPR0  		*((volatile u32 *)(BASE_ADDRESS+0x180))
#define NVIC_ICPR1  		*((volatile u32 *)(BASE_ADDRESS+0x184))

#define NVIC_IABR0  		*((volatile u32 *)(BASE_ADDRESS+0x200))
#define NVIC_IABR1  		*((volatile u32 *)(BASE_ADDRESS+0x204))

#define NVIC_IPR    		 ((volatile u8 *)(BASE_ADDRESS+0x300))

#define NVIC_STIR   		*((volatile u32 *)(BASE_ADDRESS+0xE00))

#define MNVIC_GROUP_4_SUB_0   0x05FA0300
#define MNVIC_GROUP_3_SUB_1   0x05FA0400
#define MNVIC_GROUP_2_SUB_2   0x05FA0500
#define MNVIC_GROUP_1_SUB_3   0x05FA0600
#define MNVIC_GROUP_0_SUB_4   0x05FA0700

#endif
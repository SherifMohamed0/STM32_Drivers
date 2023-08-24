/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 14 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG , BIT)     (REG |= (1<<BIT))
#define CLR_BIT(REG , BIT)     (REG &= (~(1<<BIT)))
#define TOG_BIT(REG , BIT)     (REG ^= (1<<BIT))
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#define BIT_IS_SET(REG , BIT)  (REG & (1<<BIT))
#define BIT_IS_CLR(REG , BIT)  (!(REG & (1<<BIT)))

#endif
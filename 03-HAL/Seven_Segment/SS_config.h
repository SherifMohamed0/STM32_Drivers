/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 18 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef SS_CONFIG_H
#define SS_CONFIG_H

/*Options: COMMON_ANODE
		   COMMON_CATHODE*/
		   
#define TYPE_OF_CONNECTION   COMMON_ANODE

/* Senven Segment PINS*/
/* Choose a pair of (PORT,PIN)*/
#define SS_COMMON_PIN    GPIOA , PIN0			  //			      F
#define SS_PINA 	     GPIOA , PIN1             //               |-------|
#define SS_PINB   	     GPIOB , PIN5             //             E |   G   | A
#define SS_PINC   	     GPIOA , PIN7             //               |-------|
#define SS_PIND    		 GPIOB , PIN0             //             D |       | B
#define SS_PINE   	     GPIOA , PIN2             //               |-------|
#define SS_PINF    		 GPIOA , PIN3			  //		   	      C
#define SS_PING    		 GPIOA , PIN6
#define SS_DOT_PIN    	 GPIOA , PIN0

#endif

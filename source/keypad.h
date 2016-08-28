/********************************************************************
*
*  This is a library for keypad.
*
*  ------> http://www.easymcu.ir
*  
*  Check out the links above for our tutorials and wiring diagrams
*  
*  Written by Morteza Zandi for EasyMCU.
*  BSD license, All text above must be included in any redistribution
*
**********************************************************************/

#ifndef __KEYPAD_HPP__
#define __KEYPAD_HPP__

#include "common_func.h"

const uint8_t keyCode[4][4] = {{15,14,13,12},{11,9,6,3},{0,8,5,2},{10,7,4,1}};	

class KEYPAD
{
	public:
		KEYPAD(PORT_PIN_ARRAY Pnum1, PORT_PIN_ARRAY Pnum2, PORT_PIN_ARRAY Pnum3, PORT_PIN_ARRAY Pnum4, PORT_PIN_ARRAY Pnum5, PORT_PIN_ARRAY Pnum6, PORT_PIN_ARRAY Pnum7, PORT_PIN_ARRAY Pnum8);
		void init(PORT_PIN_ARRAY Pnum1, PORT_PIN_ARRAY Pnum2, PORT_PIN_ARRAY Pnum3, PORT_PIN_ARRAY Pnum4, PORT_PIN_ARRAY Pnum5, PORT_PIN_ARRAY Pnum6, PORT_PIN_ARRAY Pnum7, PORT_PIN_ARRAY Pnum8);
		uint8_t scan(void);
	
	private:
		PORT_PIN_ARRAY pin[8];
};


#endif

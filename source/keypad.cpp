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

#include "keypad.h"

KEYPAD::KEYPAD(PORT_PIN_ARRAY Pnum1, PORT_PIN_ARRAY Pnum2, PORT_PIN_ARRAY Pnum3, PORT_PIN_ARRAY Pnum4, PORT_PIN_ARRAY Pnum5, PORT_PIN_ARRAY Pnum6, PORT_PIN_ARRAY Pnum7, PORT_PIN_ARRAY Pnum8)
{
	init(Pnum1, Pnum2, Pnum3, Pnum4, Pnum5, Pnum6, Pnum7, Pnum8);
}

void KEYPAD::init(PORT_PIN_ARRAY Pnum1, PORT_PIN_ARRAY Pnum2, PORT_PIN_ARRAY Pnum3, PORT_PIN_ARRAY Pnum4, PORT_PIN_ARRAY Pnum5, PORT_PIN_ARRAY Pnum6, PORT_PIN_ARRAY Pnum7, PORT_PIN_ARRAY Pnum8)
{
		pin[0] = Pnum1;
		pin[1] = Pnum2;
		pin[2] = Pnum3;
		pin[3] = Pnum4;
		pin[4] = Pnum5;
		pin[5] = Pnum6;
		pin[6] = Pnum7;
		pin[7] = Pnum8;
		
		io.mode(INPUT_PULLUP, pin[0], pin[1], pin[2], pin[3]);
		io.mode(OUTPUT, pin[4], pin[5], pin[6], pin[7]);
}

uint8_t KEYPAD::scan(void)
{
		uint8_t data,numKey,temp;
		numKey = 0xFF;
		temp = 0x07;
		for(uint8_t i=0;i<4;i++)
		{
			io.portWrite(temp, pin[4], pin[5], pin[6], pin[7]);
			delay.ms(2);
			data = io.portRead(pin[0], pin[1], pin[2], pin[3]) & 0x0F;
			switch(data)
			{
				case 0x07:
					numKey = keyCode[0][i];
				break;
				case 0x0B:
					numKey = keyCode[1][i];
				break;				
				case 0x0D:
					numKey = keyCode[2][i];
				break;								
				case 0x0E:
					numKey = keyCode[3][i];
				break;				
			}
			temp = ((temp >> 1)|(0x08))& 0x0F;		
		}
		return numKey;
}

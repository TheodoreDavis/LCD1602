#include "LCD1602.h"

void attach(int8_t [8]pins) {
	for (int i = 0; i < 8; i++) {
		if (i == 4 && pins[i] < 0) {
			bitMode = 1;
			break;
		}
		pinMode(pins[i], OUTPUT);
		this.pins[i] = pins[i];
	}
	
	sendByte(LCD1602_DISPLAY); //turn on lcd screen with default settings
	
	if(bitMode)
		sendByte(LCD1602_FUNCTION4BIT)
	else
		sendByte(LCD1602_FUNCTION8BIT)
	
	sendByte(LCD1602_ENTRY_MODE); //set direction
	sendByte(LCD1602_CURSOR);
}

void sendByte(uint8_t byte) { //TODO check timings and add 
	while(); //wait for lcd to be ready
	
	//send data
	digitalWrite(pins[0], byte & BIT0);
	digitalWrite(pins[1], byte & BIT1);
	digitalWrite(pins[2], byte & BIT2);
	digitalWrite(pins[3], byte & BIT3);
	
	if (!bitmode) { //8-bit mode
		digitalWrite(pins[4], byte & BIT4);
		digitalWrite(pins[5], byte & BIT5);
		digitalWrite(pins[6], byte & BIT6);
		digitalWrite(pins[7], byte & BIT7);
		
	} else {
		while(); //wait for lcd to be ready
		
		digitalWrite(pins[0], byte & BIT0);
		digitalWrite(pins[1], byte & BIT1);
		digitalWrite(pins[2], byte & BIT2);
		digitalWrite(pins[3], byte & BIT3);
	}
}
#include "LCD1602.h"

void LCD1602::start(bool use4bits) {
	this.use4bits = use4bits
	
	//set port d to outputs
	if(use4bits)
		DDRD |= 0xf0;
	else
		DDRD |= 0xff;
	
	//Tell LCD to start
	PORTD |= 0x30;
	
	delay(30);
	enable();
	delay(10);
	enable();
	delay(10);
	enable();
	
	if(use4bits)
		sendInstruction(0x2c);
	else
		sendInstruction(0x3c);
	
	sendInstruction(0x14);
	sendInstruction(0x0f);
	sendInstruction(0x06);
}

void LCD1602::sendf(const char *format, ...) {
	//TODO
}

void LCD1602::sendc(char c) {
	sendData(c);
}

void LCD1602::sendInstruction(uint8_t data) {
	PORTB &= 0xfc;
	
	transmit(data);
}

void LCD1602::sendData(uint8_t data) {
	PORTB |= 0x01;
	PORTB &= 0xfd;
	
	transmit(data);
}

int LCD1602::getPos() {
	return 0;
}

void LCD1602::clear() {
	
}

void LCD1602::moveCursor(int pos) {
	
}

//tells LCD to continously loop through the last sent string since the last clear
void LCD1602::toggleBanner() {
	banner = false;
}

void LCD1602::transmit(uint8_t data) {
	if(use4bits) {
		PORTB &= 0x0f;
		PORTB |= 0xf0 & data;
		
		enable();
		
		PORTB &= 0x0f;
		PORTB |= 0xf0 & (data << 4);
		
		enable();
	} else {
		PORTB = data;
		enable();
	}
}

void LCD1602::enable() {
	PORTB |= 0x04;
	delay(1);
	PORTB &= 0xfb;
	
}
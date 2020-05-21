/*
 * @file	LCD1602.h
 *
 * This is a library for the LCD1602
 *
 * @Author Theodore Davis
 *
 */

#ifndef __LCD1602_H__
#define __LCD1602_H__

/********************************************
	Instruction Codes:
	
********************************************/

#define LCD1602_CLEAR      (0x01)
#define LCD1602_HOME       (0x02)
#define LCD1602_ENTRY_MODE (0x06)
#define LCD1602_DISPLAY    (0x0f)

class LCD1602 {
	protected:
		uint8_t bitMode; //flag for 8bit mode
	
	public:
		void attach(int8_t [8]pins);
		void sendChar(uint8_t c);
		void sendStr(const uint8_t *format, ...)
		
	private:
		void sendByte(uint8_t byte);
}

#endif
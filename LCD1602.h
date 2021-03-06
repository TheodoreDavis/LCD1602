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
	
	****************************************/

#define LCD1602_CLEAR        (0x01)
#define LCD1602_HOME         (0x02)
#define LCD1602_ENTRY_MODE   (0x06)
#define LCD1602_DISPLAY      (0x0f)
#define LCD1602_CURSOR       (0x14)
#define LCD1602_FUNCTION4BIT (0x2C)
#define LCD1602_FUNCTION8BIT (0x3C)

/*******************************************/

/********************************************
	Byte Addresses:
	
	****************************************/

#define BIT0 (0x01)
#define BIT1 (0x02)
#define BIT2 (0x04)
#define BIT3 (0x08)
#define BIT4 (0x10)
#define BIT5 (0x20)
#define BIT6 (0x40)
#define BIT7 (0x80)

/*******************************************/

class LCD1602 {
	protected:
		bool use4bits; //flag for 8bit mode
		bool banner;
	
	public:
		void start(bool use4bits);
		void sendf(const char *format, ...);
		void sendc(char c);
		int getPos();
		void clear();
		void moveCursor(int pos);
		
	private:
		void sendInstruction(uint8_t data);
		void sendData(uint8_t data);
		void transmit(uint8_t data);
		void enable();
};

#endif
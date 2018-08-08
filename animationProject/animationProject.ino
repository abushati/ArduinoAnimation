  /*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <stdio.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 



#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);



const unsigned char PROGMEM charizard [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xE0, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0xF8, 0x03,
0xFF, 0x00, 0x00, 0x3F, 0xFE, 0x0F, 0xFF, 0xC0, 0x00, 0x7F, 0xFF, 0x1F, 0xFF, 0xC0, 0x00, 0xFF,
0xFF, 0x9F, 0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xFF,
0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x7F,
0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x03, 0xFF, 0xFF,
0xF8, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00,
0x3F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
};

const unsigned char PROGMEM star [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
0x00, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 
0x07, 0x00, 0x00, 0x07, 0x80, 0x00, 0x07, 0x80, 0x00, 0x0F, 0x80,
0x00, 0x0F, 0xC0, 0x1F, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0x03, 0xFF, 
0xFF, 0x01, 0xFF, 0xFE, 0x00, 0xFF, 0xFC, 0x00, 0x7F, 0xF0, 0x00, 
0x3F, 0xF0, 0x00, 0x7F, 0xF0, 0x00, 0x7F, 0xF0, 0x00, 0x7F, 0xF8, 
0x00, 0x7D, 0xF8, 0x00, 0xF8, 0x78, 0x00, 0xE0, 0x38, 0x00, 0xC0, 
0x0C, 0x01, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


const unsigned char PROGMEM confetti [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00,
0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0E, 0x00, 0x00,
0x0E, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00,
0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 0x80, 0x00, 0x38,
0x00, 0x00, 0x07, 0xC3, 0x80, 0x3C, 0x00, 0x00, 0x07, 0x81, 0x80, 0x1C, 0x00, 0x00, 0x0F, 0x01,
0xC0, 0x0C, 0x40, 0x00, 0x0E, 0x01, 0xC0, 0x06, 0x70, 0x00, 0x1C, 0x00, 0xC6, 0x00, 0x70, 0x00,
0x00, 0x00, 0x5E, 0x00, 0x78, 0x00, 0x00, 0x00, 0x3E, 0x60, 0x38, 0x00, 0x00, 0x00, 0x3C, 0x70,
0x3C, 0x00, 0x00, 0x00, 0x78, 0x30, 0x1C, 0x00, 0x00, 0x00, 0x40, 0x30, 0x0C, 0x00, 0x01, 0x00,
0x00, 0x30, 0x0C, 0x00, 0x03, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00,
0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
};

const unsigned char PROGMEM GTPpikachu [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00,
0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x1F, 0x80, 0x00, 0x0F, 0xC0, 0x00,
0x0F, 0x80, 0x00, 0x7F, 0x80, 0x00, 0x07, 0xC0, 0x00, 0xFF, 0x00, 0x00, 0x03, 0xEF, 0xFB, 0xFE,
0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFC, 0x06, 0x00, 0x00, 0xFF, 0xFF, 0xE0, 0x0F, 0x00, 0x00, 0x7F,
0xFF, 0x00, 0x1F, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x3F, 0x00, 0x00, 0x7F, 0xFF, 0x80, 0xFF, 0x80,
0x00, 0xFF, 0xFF, 0x81, 0xFF, 0x80, 0x00, 0xFF, 0xFF, 0x87, 0xFF, 0xC0, 0x00, 0xFF, 0xFF, 0x8F,
0xFF, 0xC0, 0x00, 0xFF, 0xFF, 0x87, 0xFF, 0xC0, 0x01, 0xFF, 0xFF, 0x87, 0xFF, 0x80, 0x01, 0xFF,
0xFF, 0xC7, 0xF8, 0x00, 0x01, 0xFF, 0xFF, 0x83, 0xE0, 0x00, 0x00, 0xFF, 0xFF, 0xC1, 0xC0, 0x00,
0x00, 0xFF, 0xFF, 0xC1, 0xC0, 0x00, 0x00, 0x7F, 0xFF, 0xC0, 0xC0, 0x00, 0x00, 0x3F, 0xFF, 0xC0,
0xE0, 0x00, 0x00, 0x7F, 0xFF, 0xC3, 0xE0, 0x00, 0x00, 0x7F, 0xFF, 0xE7, 0xC0, 0x00, 0x00, 0xFF,
0xFF, 0xE3, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE2, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE3, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xE3, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xE4,
0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF4, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF6, 0x00, 0x00, 0x00, 0x7F,
0xFF, 0xF8, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xE0,
0x00, 0x00, 0x00, 0x7F, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x3E, 0x7F, 0xC0, 0x00, 0x00, 0x00, 0x30,
0x0F, 0x00, 0x00, 0x00, 0x00, 0x40, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00 
};

const unsigned char PROGMEM kissyFace [] = {
0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF,
0xE0, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x7F,
0xFF, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x80,
0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF,
0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x3F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFE, 0x7F, 0xE0, 0xFF, 0xFC,
0x1F, 0xFE, 0xFF, 0x8F, 0x3F, 0xFB, 0xE7, 0xFE, 0xFF, 0xBF, 0x9F, 0xF7, 0xF3, 0xFF, 0xFF, 0xFF,
0xDF, 0xF7, 0xF9, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE,
0x63, 0xBF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF3, 0xBF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF7, 0xBF, 0x7F, 0xFF,
0xFF, 0xFE, 0xFF, 0xBE, 0x7F, 0xFF, 0xFF, 0xFE, 0xFF, 0xBE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xBE,
0x3F, 0xFF, 0xFF, 0xFF, 0x7F, 0x3C, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0x7C, 0x3F, 0xFF, 0xFF, 0xFF,
0x9E, 0xFC, 0x1F, 0xFF, 0xFF, 0xFF, 0xCC, 0xF8, 0x0F, 0xFF, 0xFF, 0xFF, 0xE1, 0xF0, 0x0F, 0xFF,
0xFF, 0xFF, 0xF7, 0xF0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0,
0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF,
0xFE, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x07,
0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00
};

const unsigned char PROGMEM princessCrown [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x01,
0xC0, 0x00, 0x00, 0x03, 0x80, 0x01, 0xC0, 0x00, 0x00, 0x03, 0x80, 0x01, 0xC0, 0x00, 0x00, 0x01,
0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00,
0x60, 0x03, 0x80, 0x01, 0xC0, 0x06, 0x60, 0x03, 0x80, 0x01, 0xC0, 0x06, 0x60, 0x07, 0xC0, 0x03,
0xE0, 0x06, 0x60, 0x07, 0xC0, 0x03, 0xE0, 0x06, 0x10, 0x0F, 0xE0, 0x07, 0xF0, 0x08, 0x18, 0x1F,
0xF0, 0x0F, 0xF8, 0x18, 0x0E, 0x3F, 0xF8, 0x1F, 0xFC, 0x70, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xFF, 0xFF, 0xFF,
0xFF, 0xE0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x03, 0xFF,
0xFF, 0xFF, 0xFF, 0xC0, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xC0, 0x03, 0xFF, 0xEF, 0xFF, 0xB7, 0xC0,
0x03, 0xFF, 0xFF, 0xCD, 0xB7, 0xC0, 0x03, 0xF2, 0xFF, 0xCC, 0xB7, 0xC0, 0x03, 0xEA, 0x7B, 0xAE,
0xB7, 0xC0, 0x03, 0xFC, 0x78, 0xA9, 0x5B, 0xC0, 0x01, 0xCD, 0x5A, 0xBB, 0x49, 0x80, 0x01, 0xC1,
0x52, 0xD4, 0xDB, 0x80, 0x01, 0xCF, 0xAE, 0x4F, 0x93, 0x80, 0x01, 0xDF, 0xFF, 0xFF, 0xFF, 0x80,
0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x01, 0xDF, 0xFF, 0xFF,
0xFF, 0x80, 0x01, 0xDF, 0xFF, 0xFF, 0xFF, 0x80, 0x01, 0xDF, 0xFF, 0xFF, 0xFF, 0x80, 0x01, 0xFF,
0xFF, 0xFF, 0xFF, 0x80, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x3F, 0xFF, 0xFF,
0xF8, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00,
0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x20, 0x30, 0x78, 0x45, 0x30,
0x2C, 0x20, 0x30, 0x78, 0x30, 
};


#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
int sizeNumber;
int textX;
int textY;

void whosThatPokemon(){
  display.clearDisplay();
  display.drawBitmap(0,0, princessCrown, 48, 48, WHITE);
  display.display();
  delay(10000);
  
  
}


void optionsMenu(){
  int optionNumber;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("What would you like to do baby girl?");
  display.setTextColor(WHITE,BLACK ); // 'inverted' text
  display.setCursor(3,0);
  display.println("1. Play who's that pokemon?");
  display.display();

  optionNumber = Serial.read();
  delay(10000);

  
  switch(optionNumber){
    case 1:
      whosThatPokemon();
    default:
      whosThatPokemon();
      
  }
   
}
void loveYou(){
int sizeNumber ;
//I
  for( sizeNumber = 1; sizeNumber <= 4;sizeNumber++){
  display.clearDisplay();
  display.setTextSize(sizeNumber);
  display.setTextColor(WHITE);
  display.setCursor(37,0);
  display.println("I");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.display();
  delay(500);         
  }
  delay(1000);
//LOVE 
 for( sizeNumber = 1; sizeNumber <= 4;sizeNumber++){
  display.clearDisplay();
  display.setTextSize(sizeNumber);
  display.setTextColor(WHITE);
  display.setCursor(20,0);
  display.println("LOVE");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.display();
  delay(500);       
 }
 delay(1000);
//YOU
for( sizeNumber = 1; sizeNumber <= 4;sizeNumber++){
  display.clearDisplay();
  display.setTextSize(sizeNumber);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.println("YOU");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.display();
  delay(500);       
  }
  delay(1000);
  whosThatPokemon();
  
}


void confettiDrawing(){
  int radius = 3;

  //explosion
  while (radius < 70){
    display.clearDisplay();
    display.drawCircle( 65,  20,  radius, WHITE);
    display.fillCircle(65,  20,  radius-7, WHITE);
    display.display();
    delay(70);
    radius = radius + 1;
  }

  //confetti
  for (int number = 0; number <20; number ++){
    int horzPosition = rand()% 10 ;
    display.clearDisplay();
    //0,40,80 to fill up the whole screen horizontially, Number = the confatti falling down
    display.drawBitmap(0 - horzPosition,number,confetti,48,48,WHITE);
    display.drawBitmap(40 - horzPosition,number,confetti,48,48,WHITE);
    display.drawBitmap(80 - horzPosition,number,confetti,48,48,WHITE);
    display.display();
    delay(150);
  }
  
  loveYou();         

}




void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
}
  



void loop() {
 int i;
 
 for (i = 0; i <= 100; i++){
  display.clearDisplay();
  display.drawBitmap(i, -5, charizard, 48, 48, WHITE);
  display.display();
  delay(50);
  
  //movingStar();
  if (i == 40){
    int shiftLeft = i - 5;
    int shiftRight = i + 5;
    int switchSpeed = 50;
    delay(1000);
    for (int times = 0 ; times <=20; times++) { 
      
       display.drawBitmap(shiftLeft, -5, charizard, 48, 48, WHITE);
       display.display();
       delay(switchSpeed);
       display.drawBitmap(shiftLeft, -5, charizard, 48, 48, BLACK);
       
       display.drawBitmap(shiftRight, -5, charizard, 48, 48, WHITE);
       display.display();
       delay(switchSpeed );
       display.drawBitmap(shiftRight, -5, charizard, 48, 48, BLACK);
       
       if (switchSpeed >=5)
       switchSpeed = switchSpeed - 5;
       
      }
      
      confettiDrawing();
      //loveYou();

   }
  
 }




 
}

 

/*
void movingStar(){
  int xAxis = 20;
  int yAxis = 8;
    //display.drawBitmap(xAxis, yAxis, star, 48, 48, WHITE);
    
    for ( xAxis; xAxis >=5; xAxis--){
      display.clearDisplay();
      display.drawBitmap(xAxis, yAxis, star, 48, 48, WHITE);
      display.display();
      delay(20);
      display.drawBitmap(xAxis, yAxis, star, 48, 48, BLACK); 
    }
}
*/
/*
void letterCoor (int sizeNumber){

  switch(sizeNumber){
  
    case 1:
      return textX =     
  }
 
}
*/

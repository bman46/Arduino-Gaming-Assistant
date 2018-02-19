#include <Arduino.h>
#include <Wire.h>
#include <MultiLCD.h>


LCD_SSD1306 lcd; /* for SSD1306 OLED module */
//LCD_PCD8544 lcd; /* for LCD4884 shield or Nokia 5100 screen module */
//LCD_1602 lcd; /* for LCD1602 shield */
//LCD_ZTOLED lcd; /* for ZT OLED module */
//LCD_ILI9325D lcd; /* for Itead 2.8" TFT shield */

void setup()
{
  Serial.begin(9600);
  delay(1000);
  lcd.begin();
}

void loop()
{
   if (Serial.available() > 0) {
       // read the incoming byte:
       String incomingByte = Serial.readString();
       // read temp
          lcd.setCursor(35, 0);
          lcd.setFont(FONT_SIZE_SMALL);
          lcd.print("GPU Temp:");
          
          lcd.setCursor(45, 2.5);
          lcd.setFont(FONT_SIZE_XLARGE);
          lcd.print(incomingByte);

          lcd.setCursor(70, 2.6);
          lcd.setFont(FONT_SIZE_SMALL);
          lcd.print("C");
          delay(4000);
          lcd.clear();
          
        }
 }



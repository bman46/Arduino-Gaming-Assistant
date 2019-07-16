#include <Arduino.h>
#include <Wire.h>
#include <MultiLCD.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <TimeLib.h>
//#include <time.h>


LCD_SSD1306 lcd; /* for SSD1306 OLED module */
//LCD_PCD8544 lcd; /* for LCD4884 shield or Nokia 5100 screen module */
//LCD_1602 lcd; /* for LCD1602 shield */
//LCD_ZTOLED lcd; /* for ZT OLED module */
//LCD_ILI9325D lcd; /* for Itead 2.8" TFT shield */



void setup()
{
  int incomingByte = 100;
  Serial.begin(9600);
  lcd.begin();
  lcd.setCursor(23, 0);
  lcd.setFont(FONT_SIZE_XLARGE);
  lcd.print("Starting..");
  hourFormat12();
  delay(1000);
  lcd.clear();
}
/*
void loop()
{
   if (Serial.available() > 0) {
       // read the incoming byte:
       String incomingByte = Serial.readString();
       
       //coversion from string to char:
       int str_len = incomingByte.length() + 1; 
       char data[str_len];
       incomingByte.toCharArray(data, str_len);
       
       //split string here:
       char *i;
       char *Mode = strtok_r(data,",",&i);
       char *temp = strtok_r(NULL,",",&i);
       char *kills = strtok_r(NULL,",",&i);
       char *auth = strtok_r(NULL,",",&i);
       //for tests:
       // Serial.print("Mode");
       // Serial.print(Mode);
       // Serial.print("temp");
       // Serial.print(temp);
       // Serial.print("kills");
       // Serial.print(kills);
       
       //normal mode:
       if (strcmp(auth, "99") == 0){
           if (Mode[0] == '0'){
      
              lcd.clear();
              lcd.setCursor(35, 0);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("GPU Temp:");
              
              lcd.setCursor(45, 1.8);
              lcd.setFont(FONT_SIZE_XLARGE);
              double Gtemp = atof(temp);
              lcd.print(floor(Gtemp));
      
              lcd.setCursor(70, 1.9);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("C");
              
              delay(4000);
      
              
             
            }else{
              //CS:GO mode:
              
              //normal mode stuff to test and format CSGO stuff, move back when done:
              lcd.clear();
              lcd.setCursor(35, 0);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("GPU Temp:");
              
              lcd.setCursor(45, 1.5);
              lcd.setFont(FONT_SIZE_LARGE);
              double Gtemp = atof(temp);
              lcd.print(floor(Gtemp));
      
              lcd.setCursor(70, 1.5);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("C");
      
              lcd.setCursor(38, 4.5);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("Kills:");
      
              lcd.setCursor(45, 5.5);
              lcd.setFont(FONT_SIZE_LARGE);
              lcd.print(kills);
              
              delay(4000);
            }        
       }

    }else{
      lcd.clear();
    }
 }
 */
void loop()
{
   if (Serial.available() > 0) {
       // read the incoming byte:
       String incomingByte = Serial.readString();
       
       //Serial.print(incomingByte);
       //Serial.print(now());
       //coversion from string to char:
       int str_len = incomingByte.length() + 1; 
       char data[str_len];
       incomingByte.toCharArray(data, str_len);
       
       //split string here:
       char *i;
       char *Mode = strtok_r(data,",",&i);
       char *temp = strtok_r(NULL,",",&i);
       char *kills = strtok_r(NULL,",",&i);
       char *auth = strtok_r(NULL,",",&i);

       if (incomingByte != ""){
        gettime();
       }
              
       //normal mode:
       if (strcmp(auth, "99") == 0){
           if (Mode[0] == '0'){
              
              lcd.clear();
              lcd.setCursor(35, 0);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("GPU Temp:");
              
              lcd.setCursor(30, 1.8);
              lcd.setFont(FONT_SIZE_XLARGE);
              double Gtemp = atof(temp);
              lcd.print(floor(Gtemp));
      
              lcd.setCursor(78, 1.9);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("C");
              
              delay(4000);
              lcd.clear();
              
              lcd.setCursor(43, 0);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("Time:");
              
              lcd.setCursor(25, 1.8);
              lcd.setFont(FONT_SIZE_LARGE);
              int timeh = hour();
              bool PM;
              if(timeh>12){
               PM = true;
               timeh-=12;
              } else {
                PM = false;
              }
              if(timeh>=10){
                lcd.setCursor(25, 1.8);
              } else {
                lcd.setCursor(35, 1.8);
              }
              lcd.print(timeh);
              lcd.setCursor(45, 1.8);
              lcd.print(":");
              lcd.setCursor(53, 1.8);
              lcd.print(minute());
              lcd.setCursor(80, 1.8);
              lcd.setFont(FONT_SIZE_SMALL);
              if(PM){
                lcd.print("pm");
              } else {
                lcd.print("am");
              }
             
            }else{
              //CS:GO mode:
              
              lcd.clear();
              lcd.setCursor(35, 0);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("GPU Temp:");
              
              lcd.setCursor(30, 1.5);
              lcd.setFont(FONT_SIZE_LARGE);
              double Gtemp = atof(temp);
              lcd.print(floor(Gtemp));
      
              lcd.setCursor(78, 1.5);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("C");
              
            
              lcd.setCursor(38, 4.5);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("Kills:");
      
              lcd.setCursor(45, 5.5);
              lcd.setFont(FONT_SIZE_LARGE);
              lcd.print(kills);
              
              
              delay(4000);
              lcd.clear();
              
              lcd.setCursor(43, 0);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("Time:");
              
              lcd.setCursor(25, 1.8);
              lcd.setFont(FONT_SIZE_LARGE);
              int timeh = hour();
              bool PM;
              if(timeh>12){
               PM = true;
               timeh-=12;
              } else {
                PM = false;
              }
              lcd.print(timeh);
              lcd.setCursor(45, 1.8);
              lcd.print(":");
              lcd.setCursor(53, 1.8);
              lcd.print(minute());
              lcd.setCursor(80, 1.8);
              lcd.setFont(FONT_SIZE_SMALL);
              if(PM){
                lcd.print("pm");
              } else {
                lcd.print("am");
              }
              lcd.setCursor(38, 4.5);
              lcd.setFont(FONT_SIZE_SMALL);
              lcd.print("Kills:");
      
              lcd.setCursor(45, 5.5);
              lcd.setFont(FONT_SIZE_LARGE);
              lcd.print(kills);
              delay(4000);
              
            }        
       }

    }else{
      lcd.clear();
    }
 }
 void gettime(){
  if(timeStatus()== timeNotSet){
     Serial.flush();
     const unsigned long testTime = 1357041600;
     unsigned long pctime;
     Serial.print("t");
     while(Serial.available() == 0){
      pctime = Serial.parseInt();
     }
     if (pctime > testTime){
      setTime(pctime);
     }
     
  }
     
 }



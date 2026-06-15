/*
This example will show you how to use the KY-039 heart bear sensor.
Keep Supporting Nepali Project (Study Nepal)
 */
#include <Wire.h>
#include <LiquidCrystal.h> 

LiquidCrystal lcd(2,3,4,5,6,7); 
   double alpha=0.75;
   int period=20;
   double refresh=0.0;
   
void setup(void)
{
   pinMode(A0,INPUT);
   lcd.begin(16,2);
//   lcd.backlight(); //Uncomment when using a I2C
   lcd.clear();
   lcd.setCursor(0,0);
}

void loop(void)
{
   static double oldValue=0;
   static double oldrefresh=0;
 
   int beat=analogRead(A0);
  
   double value=alpha*oldValue+(0-alpha)*beat;
   refresh=value-oldValue;
  
  
 
   lcd.setCursor(0,0);
   lcd.print(" Heart Monitor "); 
   lcd.setCursor(0,1);
   lcd.print("*Your BP is-   *");
   lcd.setCursor(12,2); 
   lcd.print(beat/10*3);
   oldValue=value;
   oldrefresh=refresh;
   delay(period*100);

  
}

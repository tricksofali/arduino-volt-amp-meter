

// include the library
#include <LiquidCrystal.h>


// initialize the interface pins
LiquidCrystal lcd(2,3,4,5,6,7);
int a,b,c;
long volt,current,power,ah;
// the 8 arrays that form each segment of the custom numbers
unsigned long msec = 0;
float time = 0.0;
int sample = 0;
float totalCharge = 0.0;
float averageAmps = 0.0;
float ampSeconds = 0.0;
long ampHours = 0;

void setup()
{
 
  lcd.begin(16, 2);
Serial.begin(9600);
}


void loop()

{
 for(int i=0;i<200;i++){
c = analogRead(A1);
a = analogRead(A0);
volt=volt+a;
  current=current+c;
 delay(1);
 }
 current=(current/200-514);
  if(current<1)current=0;
  current=current*4.8;
   volt=volt/30;
   power=(volt*current)/1000;
 //--------------------  
     sample = sample + 1;
  
  msec = millis();
  
  
  
 time = (float) msec / 1000.0;
  
 totalCharge = totalCharge + (current);
  
 averageAmps = totalCharge / sample;
  
 ampSeconds = averageAmps*time;

 ampHours = ampSeconds/3600;

 //--------------
    Serial.print(volt);
      Serial.print("  ");
        Serial.print(current);
Serial.print("  ");
        Serial.print(power);

        Serial.print("  ");
        Serial.print(ampHours);
         Serial.print("  ");
        Serial.println(time);
        
 lcd.setCursor(6,0);
  lcd.print("V");
   b=volt%10;
   lcd.setCursor(5,0);
  lcd.print(b);
   b=(volt/10)%10;
   lcd.setCursor(4,0);
  lcd.print(b);
  lcd.setCursor(3,0);
  lcd.print(".");
   b=(volt/100)%10;
  lcd.setCursor(2,0);
  lcd.print(b);
  b=(volt/1000)%10;
 lcd.setCursor(1,0);
  if(volt>999)lcd.print(b);
 else lcd.print(" ");
  
  lcd.setCursor(14,0);
  lcd.print("A");
  
   b=current%10;
     lcd.setCursor(13,0);
  lcd.print(b);
    b=(current/10)%10;
     lcd.setCursor(12,0);
  lcd.print(b);
   lcd.setCursor(11,0);
  lcd.print(".");
   b=(current/100)%10;
     lcd.setCursor(10,0);
  lcd.print(b);
 

   lcd.setCursor(6,1);
  lcd.print("W");
   b=power%10;
   lcd.setCursor(5,1);
  lcd.print(b);
   b=(power/10)%10;
   lcd.setCursor(3,1);
  lcd.print(b);
  lcd.setCursor(4,1);
  lcd.print(".");
   b=(power/100)%10;
  lcd.setCursor(2,1);
  if(power>99)lcd.print(b);
  else lcd.print(" ");
  b=(power/1000)%10;
  
  lcd.setCursor(1,1);
  if(power>999)lcd.print(b);
  else lcd.print(" ");
//------------
  lcd.setCursor(14,1);
  lcd.print("AH");
  
   b=ampHours%10;
     lcd.setCursor(13,1);
  lcd.print(b);
    b=(ampHours/10)%10;
     lcd.setCursor(12,1);
  lcd.print(b);
   lcd.setCursor(11,1);
  lcd.print(".");
   b=(ampHours/100)%10;
     lcd.setCursor(10,1);
  lcd.print(b);
     b=(ampHours/1000)%10;
     lcd.setCursor(9,1);
  lcd.print(b);
 
  delay(100);
  
}  

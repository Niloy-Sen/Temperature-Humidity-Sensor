#include <DHT.h>  
#define Type DHT11           //defines the type of sensor which is being used
#include <LiquidCrystal.h>
int sensepin=2;              //the arduino pin used for connection with the sensor
DHT HT(sensepin,Type);        //creating the object
float humidity;              //stores the humidity value
float tempC;                 //stores the temperature in Celcius
float tempF;                 //stores the temperature in Farenhite
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int settime=500;            //stores the delay time in milliseconds
void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(settime);
  lcd.begin(16,2);         //supposing our LCD has 16 columns and 2 rows
  
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity= HT.readHumidity();
  tempC= HT.readTemperature();
  tempF = HT.readTemperature(true);   //reading temperature in farenhite
  lcd.setCursor(0,0);
  lcd.print("Temp F= ");
  lcd.print(tempF);                  //prints the F temperature in the LCD
  lcd.setCursor(0,1);
  lcd.print("Humidity =");
  lcd.print(humidity);               //prints the humidity in the LCD
  lcd.print("%");
  delay(1000);
  lcd.clear();

  
  Serial.print("Humidity :");
  Serial.print(humidity);
  Serial.print("Temperature :");
  Serial.print(tempC);
  Serial.print("C");
  Serial.print(tempF);
  Serial.print("F");
  
}

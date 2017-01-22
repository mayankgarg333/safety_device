/*************************************************** 
 Look at this link for the details of how to connect a thermocouple with arduino
 --> https://www.adafruit.com/products/269
 ****************************************************/

#include <SPI.h>
#include "Adafruit_MAX31855.h"

/* Define pin numbers*/
#define DO   4
#define CS   3
#define CLK  2
#define DO1   7
#define CS1   6
#define CLK1  5
#define DO2   10
#define CS2   9
#define CLK2  8

#define maxtemp 60

/* Setup thermocouples*/
Adafruit_MAX31855 thermocouple(CLK, CS, DO);
Adafruit_MAX31855 thermocouple1(CLK1, CS1, DO1);
Adafruit_MAX31855 thermocouple2(CLK2, CS2, DO2);


void setup() {
  Serial.begin(9600);
  Serial.write("1");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // Read temperature data
  double c1 = thermocouple.readCelsius();
  double c2 = thermocouple1.readCelsius();
  double c3= thermocouple2.readCelsius();

  // Print temperature data during testing phase
  //Serial.println("C");
  //Serial.println(c1);
  //Serial.println(c2);
  //Serial.println(c3);
  
  // 500 limit only to avoid any non temperature signal to cause false alarm
if ((c1>maxtemp && c1<500)|| (c2>maxtemp && c2<500) || (c3>maxtemp && c3<500)){ 
      Serial.write("0");   
}
else
 {
     Serial.write("1");   
  }
  
delay(1000);   // wait for a second before reading
   
}

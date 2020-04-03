/*
 * This sketch reads the voltage level of an MPXV7002 pressure difference sensor and converts it to pascal (Pa).
 * The calculation may not be 100% accurate due to various factors. You can improve the accuracy by using the MPXV7002
 * with it's recommended components (e.g. the ceramic capacitors mentioned in it's datasheet) and taking multiple measurements
 * to calculate a more percise average.
 * 
 * Remember that this sensor requires a 5V input! Using a 1:2 voltage divider will make this work properly with 3.3V-Boards!
 * 
 * Released under the MIT license 2020 by Noah Meurer
 * http://nmeurer.de
 */

#define inputPin A0
#define minPressure -2000.0
#define maxPressure 2000.0
float rawValue, P;

void setup() {
  pinMode(inputPin, INPUT); 
  Serial.begin(9600); //open a serial connection
}

void loop() {
 rawValue = analogRead(inputPin); //reading the voltage level of the input pin
 P = map(rawValue, 0, 1023, minPressure, maxPressure); //converting the voltage level to Pascal (since pressure sensor measures proportional)
 Serial.println("balance: "+String(P)+" Pa"); //printing the balance of the pressure
 Serial.println("delta p: "+String(fabs(P))+" Pa"); //"calculating" delta p by just making the pressure always positive
 delay(500); //waiting so the screen doesnt get flooded
}

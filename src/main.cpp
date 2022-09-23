#include <Arduino.h> 
 
 //  I Gunjan Chaudhary, 000831804 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else.

void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 

//mapFunc for the logic of calculating and displying varied voltage
float mapFunc(long iVal, long min, long max, long desired_min, long desired_max)
{
  return (float)(iVal - min) * (desired_max - desired_min) / (float)(max - min) + desired_min;
}

void loop() { 
  int iVal; 
  String judgement;    //variable to store the final judgement string
  
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  float finalTemp = mapFunc(iVal, 0, 1023, 0, 50);      //variable to store value of final temp that is getting returned by the map function

  if (finalTemp<10.0)
  {
      judgement = "Cold!";
  }
  else if(finalTemp >10.0 && finalTemp <= 15.0){
    judgement = "Cool";
  }
  else if(finalTemp >15.0 && finalTemp <= 25.0){
    judgement = "Perfect";
  }
  else if(finalTemp >25.0 && finalTemp <= 30.0){
    judgement = "Warm";
  }
  else if(finalTemp >30.0 && finalTemp <= 35.0){
    judgement = "Hot";
  }
  else if(finalTemp >35.0){
    judgement = "Too Hot!";
  }

//string that gets printed
  Serial.println("Digitized Value to " + String(iVal) + " is equivalent to a temperature input of "+ String( mapFunc(iVal, 0, 1023, 0, 50))+" deg. C, which is "+ judgement); 
 
  // wait 2 seconds (200 ms) 
  delay(200); 
} 


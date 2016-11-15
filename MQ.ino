#include <LedControl.h>
int DIN = 12;
int CS =  11;
int CLK = 10;
LedControl lc=LedControl(DIN,CLK,CS,0); 
int sensorValue;
int pin8 = 8;
void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
}

void loop()
{
  sensorValue = analogRead(0);       // read analog input pin 0
  Serial.print(sensorValue);  // prints the value read
  Serial.println("ppm");

  if(sensorValue>100 && sensorValue<120) //checks for optimum value, can be changed
  {
    for(int row=0;row<5;row++) //lights up the 5 LEDs in the column
    lc.setLed(0,4,row,true); 
  }
  else if(sensorValue>=120) //more than optumum value
  {
    for(int row=0;row<7;row++) //lights up the 7 LEDs in the column
    lc.setLed(0,4,row,true); 
  }
  else if(sensorValue<=100) //less than optumum value
  {
    for(int row=0;row<3;row++)
    lc.setLed(0,4,row,true); //lights up the 3 LEDs in the column
  }
  delay(2000); //wait 2 seconds before turning LED off
  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,false); // turns off LED at col, row
    }
  }
  delay(1000);                        // wait 1000ms for next reading
}


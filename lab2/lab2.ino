/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:


                             
byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 }   // = 9
                             };

byte pin_number[7]= { 2,3,4,5,6,7,8};
const int buttonPin = 12;
int previosbuttonState = 0;
int presentbuttonState = 0;
int num = 0;

void setup() {               
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
  digitalWrite(9, 0);  // 關閉小數點
  digitalWrite(buttonPin,HIGH);
  pinMode(buttonPin,INPUT);
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin_number[seg], seven_seg_digits[digit][seg]);
    ++pin;
  }
}

void loop() {
  
 presentbuttonState = digitalRead(buttonPin);
  if ((previosbuttonState==0)&&(presentbuttonState==1)){
     
    num ++;
    if(num > 9){
       num = 0;
    }
  
    previosbuttonState=1;
    
  }
  else if  ((previosbuttonState==1)&&(presentbuttonState==0)) previosbuttonState=0;

  sevenSegWrite(num); 
 delay(2);

}


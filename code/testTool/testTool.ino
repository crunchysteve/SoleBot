/*
  Circuitry Test Program
  This code is a basic test program to validate that the solenoid chosen hits hard enough.

  IT DOES! You not only can't hear the solenoid operate for the drum volume (in part because the beater 
  hit's the skin before the solenoid it's its stop washer), my ears are ringing! I never got snap like this 
  out of my baby snare, using the car door lock actuators! The dynamics are provided by using analogWrite, 
  taking the value of each field of the array as as the drive value and kicking the 12v solenoid with 24v.

  The next step is to send drive to multiple solenoids, based on the MIDI note number corresponding to the
  drum they'll be fitted to, and to use MIDI velocity + 127 in analogWrite to generate soft to loud hits.

  This code is copyright 2024 Crunchysteve and is available for use or modification under an MIT licence, 
  except for commercial use, whereupon the author would appreciate a percentage of device sales in exchange 
  for a commercial licence for the manufacturer to use this project commercially.
*/

int tempo = 120;  //  change this number to change the tempo of the simple pattern below
              // ONE               two               three        &      four
int pattern[] = {255,0,0,0,0,0,0,0,176,0,0,0,0,0,0,0,192,0,0,0,0,160,0,0,176,0,0,0,0,0,0,0};
int beat = 0;     //  step counter variable
uint32_t period = 4 * 60000 / tempo / 32;   //  duration of each step

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);     //  Start serial
  Serial.println(period);   //  report period to the serial monitor
  pinMode(9,OUTPUT);        //  set pin modes for 9 and 13
  pinMode(13, OUTPUT);
}

void loop() {
  for(int i=0; i<32; i++){                  //  initiate count through the pattern
    analogWrite(9,pattern[i]);              //  trigger first note to value of "pattern[i]"
    if(pattern[i] > 0) digitalWrite(13,1);  //  and turn on the built in LED
    delay(period/3);                        //  wait for the solenoid to strike the drum
    analogWrite(9,0);                       //  turn off the power to the solenoid
    digitalWrite(13,0);                     //  turn off the LED
    delay(period - period / 3);             //  wait for the next note befor repeating
  }
}

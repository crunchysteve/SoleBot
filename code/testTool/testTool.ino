/*
  MIDI Driven Drumbot
  ©2024 Crunchysteve
  ----------------------
  This code will be the MIDI driven heart of SoléBot, the solenoid driven drumbot. 

  Dynamics are provided by using analogWrite() on channels that need them, or digitalWrite() for 
  the channels that don't, with a timed pulse to kick 12v solenoids with 24v for just long enough 
  to never exceed 24W RMS applied to each solenoid, even at maximum tempo. The MIDI note number 
  corresponding to each drum will determine which solenoid operates, while MIDI velocity + 127 
  applied to analogWrite() on the PWM outputs will generate soft to loud hits.

  This code will run on almost any micro, but the pins are setup for an Arduino Uno or Nano. 
  Use a dual AOD4184 MOSFET module, such as this one, 
    https://core-electronics.com.au/mosfet-power-switch-module.html, to drive each solenoid.

  I'm using JF-0826B 12v/2A 20N solenoids and, because of the light duty cycle, I run them from
  24V via the MOSFET boards. I haven't tried higher than 30v yet, but neither Solenoids nor the 
  MOSFETS run hot at 30v, even when run for extended periods. Non-blocking timing will be used to 
  pulse PWM drive just long enough to get the beater within a millimetre of the drum skin.
  
  All code, including C code and the OpenSCAD bracket 3D files, are hosted on
    https://github.com/crunchysteve/Solebot while,
  the OpenSCAD models are also hosted here 
    https://www.thingiverse.com/thing:6771931 without without C code.
  
  This code is copyright ©2024 Crunchysteve and is available for use or modification under an MIT 
  licence, except for commercial use, whereupon the author would appreciate a percentage of device 
  sales in exchange for any licence for manufacturing this project commercially.

  This preamble must always remain at the head of all 3d models and source code.
*/

// define output pins
#define KICK  3  //  Kick Drum PWM pin
#define CRSH  4  //  Crash Cymbal Digital pin
#define SNRE  5  //  Snare Drum PWM pin
#define HHAT  6  //  HiHat Hit   "   "
#define HOPN  7  //  HiHat Close digital pin
#define HCLS  8  //  HiHat Open     "     "
#define RTOM  9  //  Rack Tom     PWM pin
#define FTOM 10  //  Floor Tom     "   "
#define RIDE 11  //  Ride Cymbal   "   "
#define CBEL 12  //  Cowbell or Woodblock digital pin
#define LED  13  //  Will flash the LED for every step

int tempo = 120;  //  change this before upload to change the tempo of the simple pattern below
int beat = 0;                                 //  step counter variable
uint32_t period = 4 * 60000 / tempo / 32;     //  duration of each pattern step

// ONE       &       two       &       three        &      four         &
int pattern[10][32] = {
  {255,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,192,0,0,0,0,  0,0,0,  0,0,0,0,0,168,0,0}, /* Kick         */
  {  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,  0,0,0,  0,0,0,0,0,  0,0,0}, /* Crash Cymbal */
  {  0,0,0,0,0,0,0,0,184,0,0,0,0,0,0,0,  0,0,0,0,0,168,0,0,176,0,0,0,0,  0,0,0}, /* Snare        */
  {255,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,192,0,0,0,0,  0,0,0,176,0,0,0,0,162,0,0}, /* Hi-Hat Hit   */
  {  1,1,1,1,0,0,0,0,  1,1,1,0,0,0,0,0,  0,0,0,0,0,  0,0,0,  0,0,0,0,0,  0,0,0}, /* Hi-Hat Close */
  {  0,0,0,0,0,0,0,1,  0,0,0,0,0,0,0,0,  0,0,0,0,0,  0,0,0,  0,0,0,0,0,  1,1,1}, /* Hi-Hat Open  */
  {  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,192,0,0,0,0,  0,0,0,  0,0,0,0,0,168,0,0}, /* Rack Tom     */
  {  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,  0,0,0,176,0,0,0,0,  0,0,0}, /* Floor Tom    */
  {  0,0,0,0,0,0,0,0,168,0,0,0,0,0,0,0,  0,0,0,0,0,  0,0,0,  0,0,0,0,176,0,0,0}, /* Ride Cymbal  */
  {  1,0,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  1,0,0,0,0,  0,0,0,  1,0,0,0,0,  0,0,0}, /* Cowbll/Block */
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);                       //  Start serial
  Serial.println(period);                     //  report period to the serial monitor
  for(int i=KICK; i<=LED; i++){
    pinMode(i,OUTPUT);                        //  Setup all used ouputs
    digitalWrite(i,LOW);
  }
}

void loop() {
  for(int i=0; i<32; i++){                    //  initiate count through the pattern
    analogWrite(KICK,pattern[0][i]);          //  trigger kick note to value of "pattern[0][0]"
    digitalWrite(CRSH,pattern[1][i]);         //  trigger crash note to value of "pattern[1][i]"
    analogWrite(SNRE,pattern[2][i]);          //  trigger snare note to value of "pattern[2][i]"
    analogWrite(HHAT,pattern[3][i]);          //  trigger HiHat note to value of "pattern[3][i]"
    digitalWrite(HOPN,pattern[4][i]);         //  trigger Open note to value of "pattern[4][i]"
    digitalWrite(HCLS,pattern[5][i]);         //  trigger Close note to value of "pattern[5][i]"
    analogWrite(RTOM,pattern[6][i]);          //  trigger Tom note to value of "pattern[6][i]"
    analogWrite(FTOM,pattern[7][i]);          //  trigger Floor note to value of "pattern[7][i]"
    analogWrite(RIDE,pattern[8][i]);          //  trigger ride note to value of "pattern[8][i]"
    digitalWrite(CBEL,pattern[9][i]);         //  trigger cowbell note to value of "pattern[9][i]"
    digitalWrite(LED,HIGH);                   //  and turn on the built in LED
    delay(period/3);                          //  wait for the solenoid to strike the drum
    for(int i=KICK; i<=LED; i++){
      digitalWrite(i,LOW);                    //  Turn all outputs off at end of each hit
    }
    delay(period - period / 3);               //  wait for the next note is due before playing it
  }
}

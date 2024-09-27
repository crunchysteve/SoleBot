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

#ifndef PINS_H
    #define PINS_H
      //  The fields in each drum represent...
      //  MIDI note number, output pin, analog/digital out, if out has been played and at what time.
        byte DRUMS[][5] = {
                        {31,2,0,0,0},   /* Stick Click, pin 2, digital, triggered, ms */
                        {36,3,1,0,0},   /* Kick Drum, pin 3, analog, triggered, ms */
                        {49,4,0,0,0},   /* Crash Cymbal, pin 4, digital, triggered, ms */
                        {38,5,1,0,0},   /* Snare Drum, pin 5, analog, triggered, ms */
                        {44,6,1,0,0},   /* HiHat hit (half open), pin 6, analog, triggered, millis() */
                        {46,7,0,0,0},   /* HiHat hit (top lift open), pin 7, digital, 
                                                                                triggered, millis() */
                        {42,8,0,0,0},   /* HiHat hit (bottom lift close), pin 8, digital, 
                                                                                triggered, millis() */
                        {36,9,1,0,0},   /* Rack Tom, pin 9, analog, triggered, ms */
                        {43,10,1,0,0},  /* Floor Tom, pin 10, analog, triggered, ms */
                        {51,11,1,0,0},  /* Ride Cymbal, pin 11, analog, triggered, ms */
                        {56,12,0,0,0}  /* Cowbell, pin 12, digital, triggered, ms */
                      };
        byte LED = 13;          //  Will (eventually) flash the LED every quaternote from MIDI clock
#endif
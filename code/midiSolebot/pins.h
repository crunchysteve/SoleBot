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
        #define KICK 3      //  kick drum output on pin 3 - analog
        #define CRSH 4      //  crash cymbal output on pin 4 - digital
        #define SNRE 5      //  snare drum output on pin 5 - analog
        #define HHAT 6      //  HiHat cymbal beater output on pin 6 - analog
        #define HOPN 7      //  top hat cymbal lifter output on pin 7 - digital
        #define HCLS 8      //  bottom hat cymbal lifter output on pin 8 - digital
        #define RTOM 9      //  rack tom output on pin 9 - analog
        #define FTOM 10     //  floor tom output on pin 10 - analog
        #define RIDE 11     //  ride cymbal output on pin 11 - analog
        #define CBEL 12     //  cowbell or clave output on pin 12 - digital
        #define LED  13     //  Will flash the LED every quaternote from MIDI clock
#endif
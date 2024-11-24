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

//  Project Libraries
#include "percussion.h"
#include "pins.h"
#include "initialisations.h"

//  Standard Libraries
#include <MIDI.h>
#include <SoftwareSerial.h>

using Transport = MIDI_NAMESPACE::SerialMIDI<SoftwareSerial>;
SoftwareSerial mySerial = SoftwareSerial(MIDI_IN, MIDI_OUT);  //  see pins.h for MIDI serial pins
Transport serialMIDI(mySerial);
MIDI_NAMESPACE::MidiInterface<Transport> MIDI((Transport&)serialMIDI);

void handleNoteOn(byte inChannel, byte inNote, byte inVelocity){
  if(inChannel == midi_chan){
    for(int i=0; i < 11; i++){
      if(DRUMS[i][0] == inNote){
        digitalWrite(LED,HIGH);
        if(DRUMS[i][2] == 1){
          analogWrite(DRUMS[i][1],inVelocity + 128);
          DRUMS[i][3] = 1;
          DRUMS[i][4] = millis();
        } else {
          analogWrite(DRUMS[i][1],inVelocity + 128);
          digitalWrite(DRUMS[i][1],1);
          //  If hi-hat open or close, then hit it with the stick, as well.
          if(DRUMS[i][1] == HOPN || DRUMS[i][1] == HCLS) analogWrite(HHAT,inVelocity + 128);
          DRUMS[i][3] = 1;
          DRUMS[i][4] = millis();
        }
        digitalWrite(LED,LOW);
      }
    }
  }
}

void handleNoteOff(byte inChannel, byte inNote, byte inVelocity){
  if(inChannel == midi_chan){
    for(int i=0; i < 11; i++){
      if(DRUMS[i][0] == inNote){
        digitalWrite(LED,HIGH);
        if(DRUMS[i][2] == 1){
          analogWrite(DRUMS[i][1],0);
          DRUMS[i][3] = 0;
          // will start a pulse length timer here for main loop checking
        } else {
          digitalWrite(DRUMS[i][1],0);
          //  If hi-hat open or close, then turn off the stick, as well.
          if(DRUMS[i][1] == HOPN || DRUMS[i][1] == HCLS) analogWrite(HHAT,0);
          DRUMS[i][3] = 0;
          // will start a pulse length timer here for main loop checking
        }
        digitalWrite(LED,LOW);
      }
    }
  }
}

void handleNoteTimeout(){
  for(int i=0; i < 11; i++){
    if(DRUMS[i][3] && millis() >= DRUMS[i][4] + BEAT_PULSE_DURATION){
      digitalWrite(LED,HIGH);
      if(DRUMS[i][2] == 1){
        analogWrite(DRUMS[i][1],0);
        DRUMS[i][3] = 0;
      } else {
        digitalWrite(DRUMS[i][1],0);
        //  If hi-hat open or close, then turn off the stick, as well.
        if(DRUMS[i][1] == HOPN || DRUMS[i][1] == HCLS) analogWrite(HHAT,0);
        DRUMS[i][3] = 0;
      }
      digitalWrite(LED,LOW);
    }
  }
}

void setup(){
    Serial.begin(115200);
    initialise_outs(DRUMS[0][1],DRUMS[10][1]);  //  call output pin initialisations
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.begin(midi_chan);
}

void loop(){
    MIDI.read();
    handleNoteTimeout();
}
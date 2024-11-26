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

int midi_chan = CHANNEL;  //  default startup MIDI percussion channel

MIDI_CREATE_DEFAULT_INSTANCE();   //  Instantiate standard serial MIDI

void handleNoteOn(byte inChannel, byte inNote, byte inVelocity){
  if(inChannel == midi_chan){
    switch(inNote){
      case HAND_CLAP:       DRUMS[0][4] = millis();   //  MIDI note 39, pin 2, Hybrid (tone/digitalWrite), triggered, ms 
                            DRUMS[0][3] = true;       //  RD-6 will trigger a block count on SoleBot
                            if(inVelocity > 110){
                              digitalWrite(DRUMS[0][1],HIGH);
                            } else {
                              tone(DRUMS[0][1],490,BEAT_PULSE_DURATION);
                            }
                            break;
      case KICK_DRUM:       DRUMS[1][4] = millis();   //  MIDI note 36, pin 3, analogWrite(), triggered, ms
                            DRUMS[1][3] = true;
                            analogWrite(DRUMS[1][1],2*inVelocity);
                            break;
      case CRASH_CYMBAL:    DRUMS[2][4] = millis();   //  MIDI note 51, pin 4, hybrid (tone/digitalWrite), triggered, ms
                            DRUMS[2][3] = true;
                            if(inVelocity > 110){
                              digitalWrite(DRUMS[2][1],HIGH);
                            } else {
                              tone(DRUMS[2][1],490,20);
                            }
                            break;
      case ELEC_SNARE_DRUM: DRUMS[3][4] = millis();   //  MIDI note 40, pin 5, analog, triggered, ms
                            DRUMS[3][3] = true;
                            analogWrite(DRUMS[3][1],2*inVelocity);
                            break;
      case HI_HAT_HALF:     DRUMS[4][4] = millis();   //  MIDI note 44, pin 6, analog, triggered, millis()
                            DRUMS[4][3] = true;       //  Not used by RD-6
                            analogWrite(DRUMS[4][1],2*inVelocity);  //  stick hit
                            break;
      case HI_HAT_OPEN:     DRUMS[5][4] = millis();   //  MIDI note 46, pin 7, digital, triggered, millis()
                            DRUMS[5][3] = true;       //  RD-6 transmits this hi-hat message
                            digitalWrite(DRUMS[5][1],HIGH);         //  top hat lift, not used by RD-6, treated as unpedalled hit
                            analogWrite(DRUMS[4][1],2*inVelocity);  //  stick hit
                            break;
      case HI_HAT_CLOSED:   DRUMS[6][4] = millis();   //  MIDI note 42, pin 8, digital, triggered, millis() 
                            DRUMS[6][3] = true;       //  RD-6 also transmits this hi-hat message
                            digitalWrite(DRUMS[6][1],HIGH);         //  top hat close, RD-6 sends this message
                            analogWrite(DRUMS[4][1],2*inVelocity);  //  stick hit
                            break;
      case HIGH_MID_TOM:    DRUMS[7][4] = millis();   //  MIDI note 50, pin 9, analog, triggered, ms
                            DRUMS[7][3] = true;
                            analogWrite(DRUMS[7][1],2*inVelocity);  //  stick hit
                            break;
      case FLOOR_TOM_1:     DRUMS[8][4] = millis();   //  MIDI note 45, pin 10, analog, triggered, ms
                            DRUMS[8][3] = true;
                            analogWrite(DRUMS[8][1],2*inVelocity);  //  stick hit
                            break;
      case RIDE_CYMBAL:     DRUMS[9][4] = millis();   //  MIDI note 51, pin 11, analog, triggered, ms
                            DRUMS[9][3] = true;       //  Not triggered by RD-6
                            analogWrite(DRUMS[9][1],2*inVelocity);  //  stick hit
                            break;
      case COWBELL:         DRUMS[10][4] = millis();  //  MIDI note 56, pin 12, hybrid (tone/digitalWrite), triggered, ms
                            DRUMS[10][3] = true;      //  Not triggered by RD-6
                            if(inVelocity > 110){
                              digitalWrite(DRUMS[10][1],HIGH);
                            } else {
                              tone(DRUMS[10][1],490,20);
                            }
                            break;
      
      default:              break;
    }
  }
}

void handleNoteOff(byte inChannel, byte inNote, byte inVelocity){
  if(inChannel == midi_chan){
    // int thisDrum = inNote;
    switch(inNote){
      case HAND_CLAP:       DRUMS[0][3] = false;
                            noTone(DRUMS[0][1]);
                            digitalWrite(DRUMS[0][1],LOW);
                            break;
      case KICK_DRUM:       DRUMS[1][3] = false;
                            analogWrite(DRUMS[1][1],0);
                            break;
      case CRASH_CYMBAL:    DRUMS[2][3] = false;
                            noTone(DRUMS[2][1]);
                            digitalWrite(DRUMS[2][1],LOW);
                            break;
      case ELEC_SNARE_DRUM: DRUMS[3][3] = false;
                            analogWrite(DRUMS[3][1],0);
                            break;
      case HI_HAT_HALF:     DRUMS[4][3] = false;
                            analogWrite(DRUMS[4][1],0);
                            break;
      case HI_HAT_OPEN:     DRUMS[5][3] = false;
                            analogWrite(DRUMS[4][1],0);
                            break;
      case HI_HAT_CLOSED:   DRUMS[6][3] = false;
                            analogWrite(DRUMS[4][1],0);
                            break;
      case HIGH_MID_TOM:    DRUMS[7][3] = false;
                            analogWrite(DRUMS[7][1],0);
                            break;
      case FLOOR_TOM_1:     DRUMS[8][3] = false;
                            analogWrite(DRUMS[8][1],0);
                            break;
      case RIDE_CYMBAL:     DRUMS[9][3] = false;
                            analogWrite(DRUMS[9][1],0);
                            break;
      case COWBELL:         DRUMS[10][3] = false;
                            noTone(DRUMS[10][1]);
                            digitalWrite(DRUMS[10][1],LOW);
                            break;
      
      default:              break;
    }
  }
}

void handleNoteTimeout(){
  for(int i=0; i < 11; i++){
    if(DRUMS[i][3] && millis() >= DRUMS[i][4] + BEAT_PULSE_DURATION){
      if(DRUMS[i][2] == 1){
        analogWrite(DRUMS[i][1],0);
        DRUMS[i][3] = false;
      } else {
        digitalWrite(DRUMS[i][1],0);
        //  If hi-hat open or close, then turn off the stick, as well.
        if(DRUMS[i][1] == HOPN || DRUMS[i][1] == HCLS && DRUMS[i][3] == true){
          analogWrite(DRUMS[4][1],0);
          DRUMS[i][3] = false;
        }
      }
    }
  }
}

void setup(){
    MIDI.begin(midi_chan);
    initialise_outs(DRUMS[0][1],DRUMS[10][1]);  //  call output pin initialisations
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
}

void loop(){
    MIDI.read();
    handleNoteTimeout();
}
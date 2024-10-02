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

#ifndef PERCUSSION_H
    #define PERCUSSION_H
        //  MIDI Default Percussion Channel
        #define CHANNEL 10
        int midi_chan = CHANNEL;  //  default startup MIDI percussion channel
        
        //  General MIDI Percussion Table
        #define LASER 27
        #define WHIP 28
        #define SCRATCH_PUSH 29
        #define SCRATCH_PULL 30
        #define STICK_CLICK 31
        #define METRONOME_CLK 32
        #define METRONOME_BELL 33
        #define BASS_DRUM 34
        #define KICK_DRUM 36
        #define SNARE_CROSS_STICK 37
        #define SNARE_DRUM 38
        #define HAND_CLAP 39
        #define ELEC_SNARE_DRUM 40
        #define FLOOR_TOM_2 41
        #define HI_HAT_CLOSED 42
        #define FLOOR_TOM_1 43
        #define HI_HAT_HALF 44
        #define LOW_TOM 45
        #define HI_HAT_OPEN 46
        #define LOW_MID_TOM 47
        #define HIGH_MID_TOM 48
        #define CRASH_CYMBAL 49
        #define HIGH_TOM 50
        #define RIDE_CYMBAL 51
        #define CHINA_CYMBAL 52
        #define RIDE_BELL 53
        #define TAMBOURINE 54
        #define SPLASH_CYMBAL 55
        #define COWBELL 56
        #define CRASH_CYMBAL_2 57
        #define VIBRASLAP 58
        #define RIDE_CYMBAL_2 59
        #define HIGH_BONGO 60
        #define LOW_BONGO 61
        #define CONGA_DEAD_STROKE 62
        #define CONGA 63
        #define TUMBA 64
        #define HIGH_TIMBALE 65
        #define LOW_TIMBALE 66
        #define HIGH_AGOGO 67
        #define LOW_AGOGO 68
        #define CABASA 69
        #define MARACAS 70
        #define WHISTLE_SHORT 71
        #define WHISTLE_LONG 72
        #define GUIRO_SHORT 73
        #define GUIRO_LONG 74
        #define CLAVES 75
        #define HIGH_WOODBLOCK 76
        #define LOW_WOODBLOCK 77
        #define CUICA_HIGH 78
        #define CUICA_LOW 79
        #define TRIANGLE_MUTE 80
        #define TRIANGLE_OPEN 81
        #define SHAKER 82
        #define SLEIGH_BELL 83
        #define BELL_TREE 84
        #define CASTANETS 85
        #define SURDU_DEAD_STROKE 86
        #define SURDU 87
        #define SNARE_DRUM_ROD 91
        #define OCEAN_DRUM 92
        #define SNARE_DRUM_BRUSH 93
#endif
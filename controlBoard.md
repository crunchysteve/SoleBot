## MIDI Control Board

The MIDI control board for SoleBot consist of an Arduino Nano (or Uno, even a bare 328p chip if you know how to handle the bare beast) and 11 dual MOSFET DC power switch boards as solenoid drivers. The next version will also have MIDI in and through components. Here is the basic circuit diagram showing a single module on pin 9, which is the rack tom, as per pins.h definition.

![Control Board Circuit (only one driver circuit shown)](https://github.com/crunchysteve/SoleBot/blob/main/images/CircuitDiagram.png)

The current Fritzing project and its exported Gerber file are designed to have an actual Nano and 11 dual MOSFET modules either hardwired or socketed for prototyping. The plan is to eventually design a board with MIDI interface, 328P chip and MOSFET drivers laid out on a custom board as descrete components. For my current, early prototype design, I'll hardwire a standard MIDI shield as my interface to my MIDI system as an external board. I have a large, plastic, electrical junction box for a housing that will take my 24v supply (stripped of its housing), supply fan, 5v buck converter, MIDI shield and custom control board, as well as leaving room outside for some pluggable terminal blocks, as shown below...

[![Jaycar pluggable terminal block)](https://github.com/crunchysteve/SoleBot/blob/main/images/HM3202_plug-socket-12-way-screw-terminal-strip_82612.png)](https://www.jaycar.com.au/plug-socket-12-way-screw-terminal-strip/p/HM3202)

This kind of terminal block can handle 10A per carrier, more than enough for each solenoid, as the smaller 10N solenoids draw short pulses of 4A when fed with a 24v output from this system and the 60N solenoids rely on turns to generate their magnetic force from 720mA at 24 volts for their maximum 50% duty cycle at this voltage. The other advantage of this connection system is that the solenoid side (with the pins) can be cut into pairs for drive and ground, while the driver side (sockets) can be left intact and wired drive, ground, drive, ground, etc, making it easy to connect/disconnect the drum beaters with the control module. This terminal block system will be mounter on the rear of the controller box.

## How the Controller Works

[The basic Arduino C code](https://github.com/crunchysteve/SoleBot/tree/main/code) reads incoming MIDI signals from the interface (the external shield used as a MIDI board) and routes the relevent note data to available drums and percussion, detecting the note number for the available drums nad its associated velocity (how hard to hit the drum), sending this to the appropriate output as an analogWrite() for drums and cymbals, a digitalWrite() for 2 state percussion (on or off), like the hi-hat lfters and as either a tone(pin,1000) or digitalWrite() (off, half on or on) for pseudo analog control of digital channels. The latter is effectively off, 50% duty cycle and 100% duty cycle for the duration of an output's trigger pulse, because a pulse of tone, the width of a drum trigger output is half the power of simply turning that pin on with a digital write for full duty cycle to the pin for the duration of the trigger pulse.

These "pseudo-analog" outputs are useful for giving some limited dynamics to things like a woodblock or cross stick count-in, triangles, crash cymbal and rim shots, etc. Eventually, this will also allow using an analog input, or two, as a digital output (which Arduino and compatible generally allow) in either digital or pseudo-analog mode bringing the system up to 5 piece drumming with mixed percussion. An extra 6 channels of drive for those who want it, still leaving analog input 4 and 5 for I2C peripherals.

[![Driver module)](https://github.com/crunchysteve/SoleBot/blob/main/images/sny00251.jpg)](https://core-electronics.com.au/mosfet-power-switch-module.html)

The MOSFET control boards are simply fast switches that respond to 5v digital signals, from Arduino outputs, by switching switching 24v supply to operate the solenoids. The useful upper frequency limits of the solenoids will determine the tone() command pitch, or digital pulse length, on the 3 state and 2 state outputs.

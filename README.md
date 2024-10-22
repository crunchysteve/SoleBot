![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![[OpenSCAD](https://openscad.org)](https://github.com/crunchysteve/Solebot/blob/main/images/openscad.png?raw=true) ![PlatformIO](https://img.shields.io/badge/PlatformIO-%23222.svg?style=for-the-badge&logo=platformio&logoColor=%23f5822a) ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![Espressif](https://img.shields.io/badge/espressif-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white)

### [Discussions](https://github.com/crunchysteve/SoleBot/discussions) • [Wiki (Work In Progress)](https://github.com/crunchysteve/SoleBot/wiki) • [Thingiverse](https://www.thingiverse.com/thing:6771931)

# SoléBot

20241021: Just to let everybody know, waiting for some parts for the MIDI controller to arrive before I do anymore work on anything else. Beloved mother-in-law is dying and placing energies on helping the missis where I can, plus a few workshop housekeeping chores. Apologies for the limited/lack-of updates over the next few months.

---

Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW. Named "SoléBot" for the solenoid actuators used to directly beat it's drums.

***NEW*: Preliminary circuit board design for a single beater per drum, 4 piece kit. Now updated. Also, the hi-hat mech is progressing. Tonight, I prototyped it using Meccano. Only the top but, it proves the concept. Now to design the dual free clutch**

Prototyping one of the hi-hat cymbal lift arms in Meccano. it's a bit janky, but it makes me confident to proceed further on this path.

[![Prototyping one of the hi-hat cymbal lift arms in Meccano](https://img.youtube.com/vi/i6Wa3Kwags4/0.jpg)](https://youtu.be/i6Wa3Kwags4)

As well as the SoléBot testTool.ino sketch, there's now a preliminary MIDI controlled sketch that should do relatively fast (microseconds) testing for MIDI inputs and triggering solenoid outputs from those inputs with drum value, note on, note off and note timeout, if note off signals are not sent for percussion from your drum machine or DAW. So, it's now possible to start playing around with making a robotic drummer with this project.

Issues, suggestions (as an issue) and PRs are welcome. Next step will be to physically test this on actual hardware, rather than a simulation. That won't happen for a few days yet. Hey, life. Meanwhile, I've started working on a WIKI and will soon add some discussion groups to the repo.

![Simple four-piece kit layout, kick drum beater riser missing from shot](https://github.com/crunchysteve/SoleBot/blob/main/images/drumset.jpg)

*Fig. 1* - Early development photo of four-piece kit prototype.

## Parts Outline

Currently, there are solenoid mount designs for snare and toms ("beater arms") in both 3D printed plastic and aluminium, as well as a 3D printed design for the kick drum beater riser. None of these sketches are parametric nor graphical CAD files yet. You can find them in the "scadFiles" directory. The kick drum beater riser should work on larger kick drums than mine, but mine is a 16" so, if yours is a 20", it's probably too short for you. You need the "DrumClamp.scad" file to be in the same directory on your workstation as the "KickRiser.scad" file as this file calls the former file as an inclusion. The excess parts of the drum clamp are then differenced away, leaving the riser body and the solenoid mount. To make this part fit a larger drum, simply increase the z value of the translate command to bring the centre of the solenoid level with the centre of your kick drum.

The file "beaters.scad" includes a stick tip shaped beater for toms, snare and other percussion, as well as a cylyndrical beater with a rounded face for the kick. If you like a hard, wood beater, print this in PLA, or ASA, PLA flex or similar for a softer beater. These beaters screw directly on the thread that holds the solenoid's retainer nut and replaces that nut outright.

Here is the complete list of OpenSCAD files for printing or making the brackets so far...
1. beaters.scad - OpenSCAD custom functions for creating STL files for multiple tips or a kick drum beater,
2. drumBracket.scad - dimensioned drawing for creating an aluminium bracket for clamping a solenoid and beater tip to a pressed metal drum ring,
3. drumClamp.scad - dimensioned drawing for creating an 3D printed or CNC machined bracket for clamping a solenoid and beater tip to a pressed metal drum ring,
4. kickRiser.scad - dimensioned drawing for creating an 3D printed bracket for place a solenoid and beater before the beaten skin of a kick drum,
5. solenoids.scad - currently only holds a custom OpenSCAD function for a dummy JF-1250B solenoid. Other solenoids will be added as I source and find them suitable. This week, I'll be adding the JF-1250B, 60N solenoid for the hi-hat lifter solenoid to this file, possibly a provisional mechanism for the hi-hats. One of these might be good for the kick drum, too!

![hi-hat lifting solenoid compared to the drum beater solenoid](https://github.com/crunchysteve/SoleBot/blob/main/images/CymbalLifterNextToBeater.JPG)

Other parts needed will be screws and washers of various sizes (currently M3) and probably heat insert nuts for where the screws are currently driven directly into interference fit holes in my prototypes.

Help with modifying parts designs to more universal dimensions, across a broud range of kits and brands and making this parametric and easily changed, as well as translating the OpenSCAD designs to FreeCAD, would be greatly appreciated. Remember, this is a free, open source project, there's little point translating to paid or subscription software and hosting it here. Once it's in FreeCAD, it can be exported to commercial platforms and OpenSCAD exports to accessible formats, too.

<!--
10240923:- Both my printers have decided to shit their brand new hotends after about 5 prints each. I may just redesign the mechanical parts for wooden and aluminium options to suit a range of makers' tools while I try to diagnose why a high flow, high temperature hotend would clog and heat creep worse than a cheap nasty. Meanwhile, while I await new parts, -->

Here is a design for aluminium versions of the solenoid brackets. These may be closer to a universal fit than the printed prototypes, too.

![drumBracketParts](https://github.com/user-attachments/assets/1f792c37-387c-4307-ad32-f42957ae3051)
![drumBracketAssembled](https://github.com/user-attachments/assets/cf3dc659-a84e-4dcf-82a1-357d19f53589)

(OpenSCAD cad file in the relevant directory.)

---

10240920:- Now running 2 beaters at once and the test program can play multiple solenoids across a basic 4 piece kit from an Arduino UNO. MIDI will be added soon.

[![Like 2 sticks playing a practice drill!](https://img.youtube.com/vi/GSSUouHyVOM/0.jpg)](https://youtu.be/GSSUouHyVOM)

<!-- 10240919:- Initial success! And with video proof, to boot! Also, uploaded the simple Arduino test program, see "code" folder.

[![Video of a solenoid on my breadboard](https://img.youtube.com/vi/0h4IAesiM5w/0.jpg)](https://youtu.be/0h4IAesiM5w)
[![Video of my solenoid drumming test](https://img.youtube.com/vi/Kuo8L1GTG-U/0.jpg)](https://youtu.be/Kuo8L1GTG-U)

I had no ***IDEA*** my snare could sound this toppy! :D

Points to note: The sound quality isn't great, it's my iPhone SE inbuilt mic, this is just my first ever test of this method of striking a drum.

So, the things going on here... I have an Uno running [testTool.ino](./code/testTool/testTool.ino), which simply repeats the pattern, "**One**, two, three, and four." The Uno then analogWrites to pin 9 which, in turn, drives a dual AOD4184 N-channel MOSFET module, pulsing the solenoid with an average voltage of between 12v and 24 volts, depending on the value of analogWrite's second parameter. The width of the broader pulse of PWM is such that, when the tempo on a given drum is 285BPM, the RMS value at maximum (a PWM of 255) is 12v, even though the applied voltage is 24V, so my 12V solenoid won't burn out because it'll never go over 50% duty cycle. At a later stage, I'll probably code for calculating the pulses of PWM intelligently. The waveform looks like the one in this simulation, pulsewidth modulated pulses...

![Pulses of pulse width modulation](https://img.youtube.com/vi/VhJ9suvsufc/0.jpg)

While I'm still trying to decide whether to localise drum control to each drum and have a central controller that reads and redistributes the incoming MIDI signal as isolated MIDI signals for each drum, or use a single micro, like a Mega2560, this could also be done much simpler (and less musically nuanced) using a Nano or Uno and a single stick on each drum and cymbal. Hih-Hat lifting actions can be done on purely digital pins, even the crash cymbal could be "bit-banged" to create a low res pulsed PWM. I should probably prototype this way, "but bite off more than you can chew!" is my motto, LOL.

So, the snare drum will have 3 solenoids, left stick, right stick and rimshot. MIDI standards call this sidestick, but I'm going to be designing and arranging (in my DAW or drum machine) for "flatstick", where the drummer brings the stick down so that shaft hits the rim as well as the tip hitting the skin - a classic rock and blues sound, snare with a crack! MIDI "Snare 1" will trigger left stick, "Snare 2" triggers right stick, "Sidestick" will trigger right stick and rimshot together and, when hi-hat gets a left or right hit, these will override a time-adjacent left or right snare hit, respectively. 

Opening and closing the hats will be done by lifting the the top hat from half open to open and lifting the bottom hat beyond half open to close them. My kit is four piece, so my rack tom will have 2 solenoids (MIDI Toms 1 and 2) and my floor tom will have one solenoid. The ride cymbal will have 2 solenoids for rim and bell, the crash cymbal will have one solenoid. The kick will have 2 beaters (Kick 1 and 2) but operating on the one drum. Cowbell (or woodblock) rounds us out with 16 solenoids.

The next big test will be whether these JF-1250B solenoids can lift my cheap, heavy "pie plate" hi-hats. Hi-hats don't need to move up or down by much, so a lever, suspending each cymbal's clutch at half way, pivoted equally opposite the solenoids, will reduce the motion from 10mm to 5mm at the cymbal, this effectively doubles the applicable force. If the cymbals are too heavy, I'll look at some expensive 60N solenoids and hope they can do the job. These latter XRN-1564T solenoids also have longer travel, allowing for longer lifting levers, magnifying the applicable force by making it act over an even shorter relative distance at the cymbals.

There are no sticks or pedals in this system. I've 3D modelled and printed stick tips which screw directly on to the solenoid where the retainer nut screws onto the back end of the actuator shaft. The same method is applied to the kick drum, but using a larger, cylindrical beater design of around the size and shape of a wood beater contact patch. This beater will also be used for the snare rimshot solenoid, to give more mass to the rim hit, like the force of a stick. The prototypes are printed with 3mm holes, but the finished design will probably have heat-inserted, brass, M3 insert nuts for easier fitting and a forced tap on initial install.

I'll add each design and code element as I get them working. I'll also be coding the beater pulse to a maximum width to allow the beater to just reach the skin, at a MIDI velocity of 1 or so (12v peak), before power is cut. This should create a similar power dynamic to a human drummer - the harder they hit, more likely the stick is pressed and held to the skin for a short time. This timing may need a non-linear profile for optimal rebound.

```
My plans in a nutshell
  Beaters     Solenoids   Detail
    Kick        2         (Kick 1 and 2)
    Snare       3         (Left, riight and rimshot)
    Hats        4         (Left, right, open and close. Left and right will override left and right on snare)
    Tom         2         (Left and right)
    Floor       1
    Ride        3
    Cowbell     1         (No more cowbell!)
    ----------------------------------------
    Toatal     16
```
---

I've unpublished the car door lock actuator version because it was latent AF and not hard hitting enough. I'm in the process of prototyping a lighter, simpler moving mechanism using [JF-0826B](https://www.google.com/search?q=JF-0826B+solenoid&rlz=1C5CHFA_enAU930AU930&oq=JF-0826B+solenoid&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIGCAEQRRhAMgYIAhBFGDsyBggDEEUYPdIBCDQ2NDdqMGo3qAIAsAIA&sourceid=chrome&ie=UTF-8), 12V, 2A, 20N solenoids and light weight, 3D printed beater heads. I have two, quick, dirty, minimum voltage test videos here...

### KickBot
[![KickBot with a solenoid](https://img.youtube.com/vi/OM4pcrr3s-8/0.jpg)](https://youtu.be/OM4pcrr3s-8)

I'm just "spark gap" testing here, with an old, desperately-in-need-of-a-charge SLA battery. I estimate about 6 volts to a 12V, 6 ohm solenoid, so 1A and 6 watts power and it's already better volume than any test of the previous mech, with less mech noise. The plan is to have MIDI velocity equivalent to a 24v pulse, duty managed to never drive beyond 24W (12v * 2A) RMS. This mech is using a hard PLA beater replacing the retaining nut on the guide shaft which protrudes as the solenoid operates, equivalent to a wood beater. A padded beater could be made by gluing 6mm floor mat foam to the curved beater face.

### StickBot
[![StickBot with a solenoid](https://img.youtube.com/vi/Nz2LlsDFKx4/0.jpg)](https://youtu.be/Nz2LlsDFKx4)

And another "spark gap" test, with the same battery. This mech is using a hard PLA ovoid sphere, approximating a drum stick tip, again, screwed on the guide shaft, replacing the retainer nut. Apologies for the waffle, but it explains my reasons for completely throwing out the previous iteration of this project.

### HiHats
The hi-hat lifiting drive is taking a little longer to visualise with solenoid mechs, but probably involves a solenoid pulling the bottom cymbal down against a spring for "open", another pulling the top cymbal down against another spring for "closed" and a quiescent "half open" state the middle position, thus only requring power to open or close the hats, leaving them in the sizzling position by adjusting spring tensions and the clutches to balance cymbal masses. 2 stick bots will hit the cynbals in the usual way.

OpenSCAD code (and STL files) for the various brackets posted now and preliminary Arduino and Platform IO C code not too many weeks away, I hope. These test videos are faster action times, with louder strikes and less mech noise than anything I achieved with car door lock actuator motors. Yes, pneumatics whould be faster, but they're not within my budget.

## First Principles
The aim is to have a central controller that will be fed a MIDI signal from a dram machine, sequencer or DAW. That controller will communicate with sub controllers for each drum, controlling the 3 mechs for the snare (left stick, right stick, rim shot) after translating snare drum MIDI signals. The main controller is likely to be a an ESP32 powered "Cheap Yellow Display" as this gives the project the option to only require a single MIDI cable (to the controller), a daisychained 3 wire power supply (24v, 9v & gnd) to all components and internal communication with each drum's mechs via wireless protocols.

The beater mechs, to maximise striking power, will be pulsed with 24v for a MIDI 127 velocity, but the duty cycle will be managed to never exceed 50% at 4s on 285BPM, keeping the RMS power to the solenoids under 24W, even though the pulses will be 96W peak to peak. Driving the beater solenoids from the microcontrollers will be via boolean AND of pulse-on and PWM to create velocity between 1 and 127. (5 to 12 volts RMS or 0.8W to 24W RMS based on duty cycle management.) This boolean AND function will be handled calling analogWrite(PIN,VELOCITY,DURATION), where PIN is the output pin to a solenoid driver board, VELOCITY is MIDI velocity multiplied by 2 and DURATION is the maximum duration of the PWM pulse to stay within the RMS safe duty cycle at VELOCITY = 255.

This approach has been tested in an iCircuit simulation, and seems to work well, as per this proof of concept video. This was an early test, before sourcing the MOSFET modules.

[![PWM ANDed with True to provide pulsed PWM for strike and velocity control on a single output](https://img.youtube.com/vi/VhJ9suvsufc/0.jpg)](https://youtu.be/VhJ9suvsufc)

-->

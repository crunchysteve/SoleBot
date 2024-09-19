![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![[OpenSCAD](https://openscad.org)](https://github.com/crunchysteve/Solebot/blob/main/images/openscad.png?raw=true) ![PlatformIO](https://img.shields.io/badge/PlatformIO-%23222.svg?style=for-the-badge&logo=platformio&logoColor=%23f5822a) ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![Espressif](https://img.shields.io/badge/espressif-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white)
# Solebot
Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW

---
10240919:- Initial success! And with video proof, to boot! Also, uploaded the simple Arduino test program, see "code" folder.
[![Video of a solenoid on my breadboard](https://img.youtube.com/vi/0h4IAesiM5w/0.jpg)](https://youtu.be/0h4IAesiM5w)
[![Video of my solenoid drumming test](https://img.youtube.com/vi/Kuo8L1GTG-U/0.jpg)](https://youtu.be/Kuo8L1GTG-U)

I had no ***IDEA*** my snare could sound this toppy! :D

Points to note: The sound quality isn't great, it's my iPhone SE inbuilt mic, this is just my first ever test of this method of striking a drum.

So, the things going on here... I have an Uno running [testTool.ino](./code/testTool/testTool.ino), which simply repeats the pattern, "**One**, two, three, and four." The Uno then analogWrites to pin 9 which, in turn, drives a dual AOD4184 N-channel MOSFET module, pulsing the solenoid with an average voltage of between 12v and 24 volts, depending on the value of analogWrite's second parameter. The width of the broader pulse of PWM is such that, when the tempo on a given drum is 285BPM, the RMS value at maximum (a PWM of 255) is 12v, even though the applied voltage is 24V, so my 12V solenoid won't burn out because it'll never go over 50% duty cycle. At a later stage, I'll probably code for calculating the pulses of PWM intelligently. The waveform looks like the one in this simulation, pulsewidth modulated pulses...

[![Pulses of pulse width modulation](https://img.youtube.com/vi/VhJ9suvsufc/0.jpg)](https://www.youtube.com/watch?v=VhJ9suvsufc)

The snare drum will have 3 solenoids, left stick, right stick and rimshot. MIDI standards call this sidestick, but I'm going to be designing and arranging (in my DAW or drum machine) for "flatstick", where the drummer brings the stick down so that shaft hist the rim as well as the tip hitting the skin - a classic rock and blues sound, snare with a crack! MIDI "Snare 1" will trigger left stick, "Snare 2" triggers right stick, "Sidestick" will trigger right stick and rimshot together and, when hi-hat gets a left or right hit, these will override a time-adjacent left or right snare hit, respectively. 

Opening and closing the hats will be done by lifting the the top hat from half open to open and lifting the bottom hat beyond half open to close them. My kit is four piece, so my rack tom will have 2 solenoids (MIDI Toms 1 and 2) and my floor tom will have one solenoid. The ride cymbal will have 2 solenoids for rim and bell, the crash cymbal will have one solenoid. The kick will have 2 beaters (Kick 1 and 2) but operating on the one drum. Cowbell (or woodblock) rounds us out with 16 solenoids.

The next big test will be whether these JF-1250B solenoids can lift my cheap, heavy "pie plate" hi-hats. Hi-hats don't need to move up or down by much, so a lever, suspending each cymbal's clutch at half way, pivoted equally opposite the solenoids, will reduce the motion from 10mm to 5mm at the cymbal, this effectively doubles the applicable force. If the cymbals are too heavy, I'll look at some expensive 60N solenoids and hope they can do the job. These latter XRN-1564T solenoids also have longer travel, allowing for longer lifting levers, magnifying the applicable force by making it act over an even shorter relative distance at the cymbals.

There are no sticks or pedals in this system. I've 3D modelled and printed stick tips which screw directly on to the solenoid where the retainer nut screws onto the back end of the actuator shaft. The same method is applied to the kick drum, but using a larger, cylindrical beater design of around the size and shape of a wood beater contact patch. This beater will also be used for the snare rimshot solenoid, to give more mass to the rim hit, like the force of a stick. The prototypes are printed with 3mm holes, but the finished design will probably have heat-inserted, brass, M3 insert nuts for easier fitting and a forced tap on initial install.

I'll add each design and code element as I get them working. I'll also be coding the beater pulse to a maximum width to allow the beater to just reach the skin, at a MIDI velocity of 1 or so (12v peak), before power is cut. This should create a similar power dynamic to a human drummer - the harder they hit, more likely the stick is pressed and held to the skin for a short time. This timing may need a non-linear profile for optimal rebound.

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


![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![[OpenSCAD](https://openscad.org)](https://github.com/crunchysteve/Solebot/blob/main/images/openscad.png?raw=true) ![PlatformIO](https://img.shields.io/badge/PlatformIO-%23222.svg?style=for-the-badge&logo=platformio&logoColor=%23f5822a) ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![Espressif](https://img.shields.io/badge/espressif-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white)
# Solebot
Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW

---
20240913: Over the next month I hope to upload some rudimentary Arduino code and begin testing the kick and snare mechs. If I'm happy with the result, I'll be proceeding with the project. If not, I'll look into what I can do, designwise, to make the project make me happy enough to proceed.

---

I've unpublished the car door lock actuator version because it was latent and not hard hitting enough. I'm in the process of prototyping a lighter, simpler moving mechanism using [JF-0826B](https://www.google.com/search?q=JF-0826B+solenoid&rlz=1C5CHFA_enAU930AU930&oq=JF-0826B+solenoid&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIGCAEQRRhAMgYIAhBFGDsyBggDEEUYPdIBCDQ2NDdqMGo3qAIAsAIA&sourceid=chrome&ie=UTF-8), 12V, 2A, 20N solenoids and light weight, 3D printed beater heads. I have two, quick, dirty, minimum voltage test videos here...

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

The beater mechs, to maximise striking power, will be pulsed with 24v for a MIDI 127 velocity, but the duty cycle will be managed to never exceed 25% duty cycle, keeping the RMS power to the mechs under 24W, even though the pulses will be 96W peak to peak. Driving the beater solenoids from the microcontrollers will be via boolean AND of pulse-on and PWM to create velocity between 1 and 127. (5 to 12 volts RMS or 0.8W to 24W RMS based on duty cycle management.) This boolean AND function will be handled calling analogWrite(PIN,VELOCITY,DURATION), where PIN is the output pin to a solenoid driver board, VELOCITY is MIDI velocity multiplied by 2 and DURATION is the maximum duration of the PWM pulse to stay within the RMS safe duty cycle at VELOCITY = 255.

This approach has been tested in an iCircuit simulation, and seems to work well, as per this proof of concept video. This was an early test, before sourcing the MOSFET modules.

[![PWM ANDed with True to provide pulsed PWM for strike and velocity control on a single output](https://img.youtube.com/vi/VhJ9suvsufc/0.jpg)](https://youtu.be/VhJ9suvsufc)


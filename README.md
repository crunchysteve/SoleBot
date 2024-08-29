# Solebot
Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW

---

I've unpublished the car door lock actuator version because it was latent and not hard hitting enough. I'm in the process of prototyping a lighter, simpler moving mechanism using [JF-0826B](https://www.google.com/search?q=JF-0826B+solenoid&rlz=1C5CHFA_enAU930AU930&oq=JF-0826B+solenoid&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIGCAEQRRhAMgYIAhBFGDsyBggDEEUYPdIBCDQ2NDdqMGo3qAIAsAIA&sourceid=chrome&ie=UTF-8), 12V, 2A, 20N solenoids and light weight, 3D printed beater heads. I have two, quick, dirty, minimum voltage test videos here...

### KickBot
[![KickBot with a solenoid](https://img.youtube.com/vi/OM4pcrr3s-8/0.jpg)](https://youtu.be/OM4pcrr3s-8)

I'm just "spark gap" testing here, with an old, desperately-in-need-of-a-charge SLA battery. I estimate about 6 volts to a 12V, 6 ohm solenoid, so 1A and 6 watts power and it's already better volume than any test of the previous mech, with less mech noise. The plan is to have MIDI velocity equivalent to a 24v pulse, duty managed to never drive beyond 24W (12v * 2A) RMS. This mech is using a hard PLA beater replacing the retaining nut on the guide shaft which protrudes as the solenoid operates, equivalent to a wood beater. A padded beater could be made by gluing 6mm floor mat foam to the curved beater face.

### StickBot
[![StickBot with a solenoid](https://img.youtube.com/vi/Nz2LlsDFKx4/0.jpg)](https://youtu.be/Nz2LlsDFKx4)

another "spark gap" test, with the same battery. This mech is using a hard PLA ovoid sphere, approximating a drum stick tip, again, screwed on the guide shaft, replacing the retainer nut. Apologies for the waffle, but it explains my reasons for completely throwing out the previous iteration of this project.

### HiHats
The hi-hat drive is taking a little longer to visualise with solenoid mechs, but probably involve a solenoid pulling the bottom cymbal down against a spring for "open", another pulling the top cymbal down against another spring for "closed" and a quiescent "half open" state the middle position, thus only requring power to open or close the hats, leaving them in the sizzling position by adjusting spring tensions to balance cymbal masses. 2 stick bots will hit the cynbals in the usual way.

I'll post my OpenSCAD code (and STL files) for the various brackets soon and arduino code as that becomes public ready. These test videos are faster action times, with louder strikes and less mech noise than anything I achieved with car door lock actuator motors. Yes, pneumatics whould be faster, but they're not 
within my budget.

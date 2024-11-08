![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![[OpenSCAD](https://openscad.org)](https://github.com/crunchysteve/Solebot/blob/main/images/openscad.png?raw=true) ![PlatformIO](https://img.shields.io/badge/PlatformIO-%23222.svg?style=for-the-badge&logo=platformio&logoColor=%23f5822a) ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![Espressif](https://img.shields.io/badge/espressif-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white)

### [Discussions](https://github.com/crunchysteve/SoleBot/discussions) • [Wiki (Work In Progress)](https://github.com/crunchysteve/SoleBot/wiki) • [Thingiverse](https://www.thingiverse.com/thing:6771931) • [News](https://github.com/crunchysteve/SoleBot/discussions/categories/news)

### [New Poll](https://github.com/crunchysteve/SoleBot/discussions/10)

[What is SoléBot?](#solébot) - [Background](#background) - [Reasons](#why) - ![Progress](#progress)
[Scope](#scope) - [Contribution & Maintenance](#contribution-and-maintenance)

# SoléBot

Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW. Named "SoléBot" for the solenoid actuators used to directly beat the drums.

# Background

Hi, I'm "Crunchy." (Steve to people among my family and friends.)

As a semi-pro, live musician for close to 40 years of my 63 years alive, I've watched live bands, particularly electric bands at the pub music level, struggle to compete with DJs and recorded entertainment, because one paycheck is cheaper than two, three or "insert band size here" paychecks. Drum machines, bands in boxes and Digital Audio Workstations have helped a little, and even swing, but the sounds in even the best drum machines, while dynamic, are often too perfect. Every hit, at a given velocity in a given drum set, sounds the same, unlike a human drummer. I want a system that has inherent, "human like" imperfections that make every stroke sound like a human played it, while still allowing a solo artist to perform to pre-recorded backing tracks, and I want this to be as affordable and accessible as anything in today's typical home studio.

Hence, SoléBot, the solenoid operated drumming robot. The aim is to develop a multi-output control board that can drive solenoids to beat drums, cymbals and other percussion, as commanded by MIDI data from a drum machine or DAW. I envisage this control board being adaptable to other instruments, like bass guitar, too. I'll be occasionally demonstrating developments working on my youtube channel, too, in [this playlist](https://www.youtube.com/playlist?list=PLrngkZ75bHDKrJ51mYCRLDtqRJ-8iNQGl).

[There's news](https://github.com/crunchysteve/SoleBot/discussions/8). I've now proven the electronics work with a simple four-on-the-floor, hard-coded drum beat, [testTool.ino](https://github.com/crunchysteve/SoleBot/tree/main/code/testTool). See below in [Progress](#progress).

The microlatencies inherent in simple, 16 bit microcontrollers, like the entry-level boards of the Arduino family, plus the flex and movement of brackets holding the solenoids that drive the beaters, onto the instruments they're set to beat, lend themselves to a real-world sound. Tighter than a human, looser than a drum machine. A band in a road case or two on wheels, rolled into pubs and house parties, no more setup than a fancy DJ rig, all the excitement of a live performance by the human artist out front, backed by their robotic, imperfect band of machines.

If I still played live, I'd work for the same fee as an emerging DJ. In an all human, live band, that's at least three paychecks to the DJ's solitary fee. As "Crunchy and His Machines," it's one paycheck and still a live show, full of excitement, surprises, "accidentally" missed beats with encores and jokes with the crowd.

So, the key is simplicity of equipment, the lone, high school, outcast nerd (my people of 40+ years ago and today represent!) can build their own band, literally, from accessible parts, in a platform that affords learning, then set out to rule a stage, if not the world. Arduino (Nano to Mega), C (at first, later Micropython? Javascript?), a MIDI to USB interface and a tablet with an app, any MIDI capable app. Then sound like a real band, not a band-in-a-box.

[![Early proof-of-concept running a hardware test loop, driving 2 solenoids on a snare drum](https://img.youtube.com/vi/GSSUouHyVOM/0.jpg)](https://youtu.be/GSSUouHyVOM)

Early proof-of-concept running a hardware test loop, driving 2 solenoids on a snare drum

# Why?

Well, why not? Yeah, there are others who have done this, and they're great! Most that I've seen don't appear to be more generalised, though, at least in the FOSS/OSS arena. I want to create a system of tools that can be used as a why to create a way to use MIDI to drive any drum or percussion rig, using whatever instrument(s) you play, of the shelf hardware *or* 3D printing to mount simple beaters. Nearly every other robo drummer I've seen has been built to work with the builder's drumkit. I want SoléBot to be generalised and adaptable, able to be driven via MIDI, USB MIDI and wireless MIDI. And this flexibility, using simple microcontrollers, makes it more accessible, too.

I'd also like to see the electronics and firmware adapted to play other instruments, like my main instrument, bass guitar. This may require microcontrollers with more outputs than a 328P system for extreme examples, but it's more-or-less just as easy to do, with a modular, open source platform like I'm atempting to create with this project.

Then there's what I believe might be the killer app. **Making the drums (at first) playable by somebody who only plays EDM instruments**. To paraphrase Fatboy Slim, you'd only need a 606! Imagine using a Behringer RD6 or a Roland TR-06 (Behringer's and Roland's reboots of the original TR-606, respectively) to play drums! **LIVE!** Playing the 606 back in the 80s was a fundamentally life-changing experience for me, it made beat composition so easy, I was even able to write down the patterns I created, in proper notation, to give to the drummer in my band. There was no MIDI on the 606, there *is* on the RD6 and the 06! 

I genuinely beleive the 606's beat programming model one of the best drum machine user interfaces of all time! You start the machine on a blank pattern, at the kick drum, watch the red LEDs step through the empty pattern, then add a 1 and a 3, the pattern reaches the end and sequences through again and... doof, (rest), doof, (rest), bar after bar, magic! Press another button, the pattern becomes doof, (rest), da-doof, (rest), interesting... switch to snare, tap the 2 and the 4, but fill in the 3 spots after the 4, too, *a snare fill!* It continues to play, while you create changes, all with a single pattern, layer after layer, selected with a simple rotary switch. A billion bedroom producer House Music fans can't be wrong!

And now the MIDI reincarnations of the 606 make this available for playing real drums live **WHEN YOU"RE NOT A DRUMMER!** Because the modern versions have MIDI and SoléBot is already a prototype MIDI percussion robot development kit, just self source your parts. Classic, retro designs and skills used with a free open source software community project on flexible hardware. EDM skills become *RAWK!* Rock becomes a block rockin' *BEAT.* Crazy ideas are how the arts evolve, how the tired or classic old becomes rejevenated, different, exciting!

If that's not a killer app for musical robotics then, as the dadaists and punks claimed, art is dead and f*** art, dance instead. Not to mention, drumming access for the disabled! Killer app in every way!

# Progress

To date, the project consists of a hardware test program - a repeating, four-on-the-floor loop that's been tested on an Arduino UNO and Nano (testTool), as well as a rudimentary, non-blocking MIDI reader code base that assigns MIDI notes and velocities from channel 10 to analogWrite() outputs and digitalWrite() outputs based on whether loudness control is needed or just simple on/off. The latter MIDI reader code hasn't been run on the MarkMothersboard yet, didn't crash a nano it was uploaded to, with extra Serial.println() commands to call when events happened as it looped through MIDI. It seems to work, at this stage.

A "motherboard" style circuit board has been designed (nicknamed "MarkMothersboard") but there are some small bugs with this already. On the imput side of the MOSFET driver boards, it's advised to connect all three data in and ground pins on the controller module to all three motherboard holes for input and ground, each. As this is primarily a prototype board to get a prototype kit running from my Alesis drum machine, I see no serious problems with using off-the-rack modules on a through-hole motherboard. Once the basic, minimal design is proven to work adequately, a more compact board, using discreet micro(s) (Atmel 328p or ATMega 2650 for more outputs), MOSFETs and supporting parts can be developed. Faster, higher bitdepth boards may reduce the random latencies of varying throughput, but those random latencies are the art introducing huamn feel to the playing. These older microcontrollers also help keep the cost down, improving accessibility to younger artists, who may not receive assistance from parents for "wasteful" things like music, but not yet in the workforce because of studies.

[![This is the SoléBot motherboard running the hardware test code.](https://img.youtube.com/vi/qrn4sm5H3BI/0.jpg)](https://www.youtube.com/watch?v=qrn4sm5H3BI)

The YouTube video link, above, shows the SoléBot motherboard running the hardware test code that is used to play a simple, repetitive, four-on-the-floor while attaching solenoids and hardware to a drumkit.

# Scope

The main focus of this project is the controller and the firmware, although, providing template-based bracket designs (currently OpenSCAD format and far from universal mounting) and a basic logic and driver hardware platform is important, too. As the project needs to remain simple and beginner friendly, staying with the Arduino platform provides people, who want to undertake their own robotic drumkit project, with a wide support network for learning and solutions. This doesn't rule out other platforms (like micropython or tinyGo) at a later stage, but C/C++ in Arduino is the primary target of this project.

Note: I use platformIO for other projects, but this should stay in ArduinoIDE format, again for accessibility for beginners and the less technological. I'm writing in VSCode for its git tools, but verifying/uploading the code to hardware from ArduinoIDE. I'd like to see this project stay at least available in this format. I have no problem with a PlatformIO version being the main format eventually, but only provided it's ported to ArduinoIDE format at release stages, for accessibility.

Initially, the project's aim is to develop a "single beater per drum," four piece kit using 328p controllers, purely for the simplicity of this platform. Larger kits, with "two-handed" emulations on snare and hats, double kick, etc, and ethnic or orchestral percussion systems could be developed. The Nano's analog ports are proken ot to header pins on the motherboard, to allow use as digital outputs for nondynamic actuators, like hihat lifters.

That said, there is room for the hardware and firmware to be adapted (possibly forked) outside of percussion instruments, even to guitar and bass and, in the extreme wind, brass, strings and keys. However, as the complexity rises, I envisage these being third party forks from SoléBot, which should always be kept simple - imagine Jack White with a robotic kit rather than Meg. (Meg *might* have been less likely to have a breakdown if she'd never had the pressure of fame??? Who knows.)

# Contribution and Maintenance

I'm currently the sole maintainer. To be totally honest, I'm one of those "beginners" and "hobbyists" that I want this project to serve. It shows, I know. Industrial design, audio production and hardware technical support (workplace trainer) are my primary skillset. I "code" the best I can. If you can see a better way to structure a function or a method, please, use Issues and Pulls for all you're worth.

This project is EXPRESSLY NOT a money making project. I have created a modified MIT Licence that requires any commercial concern, wishing to make off-the-rack products from any part or whole of project IP, negotiate a licence fee if, heavens forbid, this ever takes off like 3D printing did. Such a licence fee would be used solely for maintaining and developing the project. It might pay for something like an "office Christmas party" once a year, but it will never line my pocket or any other maintainer's. Again, it's about accessiblity, *public ownership* and freedom of access to ideas.

If you want to help run the repo, pull, pull, pull successfully a few times. If you're a nice person and committed to the goals, you're probably in. Please read the Code of Conduct before asking and lodge a few successful pull requests first. If you're a really active submitter of really good issues and feature requests that get listed in a roadmap, but not a great coder, there's still a place for you. We'll find ways you can help more formally, like forwarding the right issues to the right skilled maintainer, admin, accounting. I want this project to be a community.

Cheers,
Crunchy.

PS: As always, this is an open project. If you can see a better way to do any part of this, post a feature request in the discussions, raise an issue, or offer your code with a pull request.

![repaired prototype board](https://github.com/crunchysteve/SoleBot/blob/main/images/SoleBotPCBV1.1∂_pcb.png)

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![[OpenSCAD](https://openscad.org)](https://github.com/crunchysteve/Solebot/blob/main/images/openscad.png?raw=true) ![PlatformIO](https://img.shields.io/badge/PlatformIO-%23222.svg?style=for-the-badge&logo=platformio&logoColor=%23f5822a) ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![Espressif](https://img.shields.io/badge/espressif-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white)

### [Discussions](https://github.com/crunchysteve/SoleBot/discussions) • [Wiki (Work In Progress)](https://github.com/crunchysteve/SoleBot/wiki) • [Thingiverse](https://www.thingiverse.com/thing:6771931) • [News](https://github.com/crunchysteve/SoleBot/discussions/categories/news)

# SoléBot

Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW. Named "SoléBot" for the solenoid actuators used to directly beat the drums.

Hi, I'm "Crunchy." (Steve to people among my family and friends.)

As a semi-pro, live musician for close to 40 years of my 63 years alive, I've watched live bands, particularly electric bands at the pub music level, struggle to compete with DJs and recorded entertainment, because one paycheck is cheaper than two, three or "insert band size here" paychecks. Drum machines, bands in boxes and Digital Audio Workstations have helped a little, and even swing, but the sounds in even the best drum machines, while dynamic, are often too perfect. Every hit, at a given velocity in a given drum set, sounds the same, unlike a human drummer. I want a system that has inherent, "human like" imperfections that make every stroke sound like a human played it, while still allowing a solo artist to perform to pre-recorded backing tracks, and I want this to be as affordable and accessible as anything in today's typical home studio.

Hence, SoléBot, the solenoid operated drumming robot. The aim is to develop a multi-output control board that can drive solenoids to beat drums, cymbals and other percussion, as commanded by MIDI data from a drum machine or DAW. I envisage this control board being adaptable to other instruments, like bass guitar, too.

The microlatencies inherent in simple, 16 bit microcontrollers, like the entry-level boards of the Arduino family, plus the flex and movement of brackets holding the solenoids, that drive the beaters, onto the instruments they're set to beat, lend themselves to a real-world sound. Tighter than a human, looser than a drum machine. A band in a road case or two on wheels, rolled into pubs and house parties, no more setup than a fancy DJ rig, all the excitement of a live performance by the human artist out front, backed by their robotic, imperfect band of machines.

If I still played live, I'd work for the same fee as an emerging DJ. In an all human, live band, that's at least three paychecks to the DJ's solitary fee. As "Crunchy and His Machines," it's one paycheck and still a live show, full of excitement, surprises, "accidentally" missed beats and encores and jokes with the crowd.

So, the key is simplicity of equipment, so the lone, high school, outcast nerd (my people represent!) can build their own band, literally, from accessible parts, in a platform that affords learning, and set out to rule a stage, if not the world. Arduino (Nano to Mega), C (at first, later Micropython? Javascript?), a MIDI to USB interface and a tablet with an app, any MIDI capable app. And sound like a real band, not a band-in-a-box.

[![Early proof-of-concept running a hardware test loop, driving 2 solenoids on a snare drum](https://img.youtube.com/vi/GSSUouHyVOM/0.jpg)](https://youtu.be/GSSUouHyVOM)

Early proof-of-concept running a hardware test loop, driving 2 solenoids on a snare drum

# Progress

To date, the project consists of a hardware test program, a repeating, four-on-the-floor loop that's been tested on an Arduino UNO and Nano (testTool), and a rudimentary, non-blocking MIDI reader code base that assigns MIDI notes and velocities from channel 10 to analogWrite() outputs and digitalWrite() outputs based on whether loudness control is needed or just simple on/off. (midiSolebot) The latter hasn't been tested beating drums, but testTool has (above video) and can handle dynamics.

A "motherboard" style circuit board has been designed but there are some small bugs with this already. On the imput side of the MOSFET driver boards, it's advised to connect all three data in and ground pins on the controller module to all three motherboard. As this is primarily a prototype board to get a prototype kit running from my Alesis, I see no serious problems with using off-the-rack modules on a through-hole motherboard. Once the basic, minimal design is proven to work adequately, a more compact board, using discreet micro(s) (Atmel 328p or ATMega 2650 for more outputs), MOSFETs and supporting parts can be developed. Faster, higher bitdepth boards may reduce the random latencies of varying throughput, but those random latencies are the art introducing huamn feel to the playing. These older microcontrollers also help keep the cost down, improving accessibility to younger artists, who may not receive assistance from parents for "wasteful" things like music, but not yet in the workforce because of studies.

Yeah, I'm channelling aspects of my youth of *MANY* years ago. The struggle is still real today. Mums and dads everywhere still say, "[Get a haircut and get a real job.](https://www.youtube.com/watch?v=3w7CrxLj36I)" I've been guilty of this, sort of, with my own kids. Hey, you want the best for them and for them to be safe, OK.

# Scope

The main focus of this project is the controller and the firmware, although, providing template-based bracket designs (currently OpenSCAD forma and far from universal mounting) is important, too. As the project needs to remain simple and beginner friendly, staying with the Arduino platform provides people, who want to undertake their own robotic drumkit project, with a wide support network for learning and solutions. This doesn't rule out other platforms (like micropython or tinyGo) at a later stage, but C/C++ in Arduino is the primary target of this project.

Note: I use platformIO for other projects, but this should stay in ArduinoIDE format, again for accessibility for beginners and the less technological. I'm writing in VSCode for its git tools, but verifying/uploading the code from ArduinoIDE. I'd like to see this project stay at least available in this format. I have no problem with a PlatformIO version being the main format, provided it's always ported to ArduinoIDE format at release stages

Initially, the project's aim is to develop a "single beater per drum," four piece system using 328p controllers, purely for the simplicity of this platform. Larger kits, with "two-handed" emulations on snare and hats, double kick, etc, and ethnic or orchestral percussion systems could be developed. That said, there is room for the hardware and firmware to be adapted (possibly forked) outside of percussion instruments, even to guitar and bass and, in the extreme wind, brass, strings and keys. However, as the complexity rises, I envisage these being third party forks from SoléBot, which should always be kept simple - imagine Jack White with a robotic kit rather than Meg. (Meg *might* have been less likely to have a breakdown if she'd never had the pressure of fame??? Who knows.)

# Contribution and Maintenance

I'm currently the sole maintainer. To be totally honest, I'm one of those "beginners" and "hobbyists" I want this project to serve. It shows, I know. Industrial design, audio production and hardware technical support (workplace trainer) are my primary skillset. I "code" the best I can. If you can see a better way to structure a function or a method, please, use Issues or Pulls for all you're worth.

This project is EXPRESSLY NOT a money making project. I have created a modified MIT Licence that requires any commercial concern, wishing to make off-the-rack products from any part or whole of project IP, negotiate a licence fee if, heavens forbid, this ever takes off like 3D printing did. Such a licence fee would be used solely for maintaining and developing the project. It might pay for something like an "office Christmas party" once a year, but it will never line my pocket or any other maintainer's. Again, it's about accessiblity, *public ownership* and freedom of access to ideas.

If you want to help run the repo, pull, pull, pull successfully a few times. If you're a nice person and committed to the goals, you're probably in. Please read the Code of Conduct before asking and lodge a few successful pull requests first. If you're a really active submitter of really good issues and feature requests that get listed in a roadmap, but not a great coder, there's still a place for you. We'll find ways you can help more formally, like forwarding the right issues to the right skilled maintainer. I want this project to be a community.
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![[OpenSCAD](https://openscad.org)](https://github.com/crunchysteve/Solebot/blob/main/images/openscad.png?raw=true) ![PlatformIO](https://img.shields.io/badge/PlatformIO-%23222.svg?style=for-the-badge&logo=platformio&logoColor=%23f5822a) ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![Espressif](https://img.shields.io/badge/espressif-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white)

### [Discussions](https://github.com/crunchysteve/SoleBot/discussions) • [Wiki (Work In Progress)](https://github.com/crunchysteve/SoleBot/wiki) • [Thingiverse](https://www.thingiverse.com/thing:6771931) [News](https://github.com/crunchysteve/SoleBot/discussions/categories/news)

# SoléBot

20241021: Just to let everybody know, waiting for some parts for the MIDI controller to arrive before I do anymore work on anything else. Beloved mother-in-law is dying and placing energies on helping the missis where I can, plus a few workshop housekeeping chores. Apologies for the limited/lack-of updates over the next few months.

---

Solenoid operated, adaptable, robotic drumkit to play real drums from a MIDI drum machine or DAW. Named "SoléBot" for the solenoid actuators used to directly beat it's drums.

Preliminary circuit board design for a single beater per drum, 4 piece kit. Now updated. Also, the hi-hat mech is progressing. Tonight, I prototyped it using Meccano. Only the top but, it proves the concept. Now to design the dual free clutch**

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
4. kickRiser.scad - dimensioned drawing for creating an 3D printed bracket for a solenoid and beater in front of the beaten skin of a kick drum,
5. solenoids.scad - currently only holds a custom OpenSCAD function for dummy JF-0826B 20N and JF-1250B 60N solenoids. Other solenoids may be added as I source and find them suitable.

![hi-hat lifting solenoid compared to the drum beater solenoid](https://github.com/crunchysteve/SoleBot/blob/main/images/CymbalLifterNextToBeater.JPG)

Other parts needed will be screws and washers of various sizes (currently M3) and probably heat insert nuts for where the screws are currently driven directly into interference fit holes in my prototypes.

Help with modifying parts designs to more universal dimensions, across a broad range of kits and brands and making this parametric and easily changed, as well as translating the OpenSCAD designs to FreeCAD, would be greatly appreciated. Remember, this is a free, open source project, there's little point translating to paid or subscription software and hosting it here. Once it's in FreeCAD, it can be exported to commercial platforms and OpenSCAD exports to accessible formats, too.

Here is a design for aluminium versions of the solenoid brackets. These may be closer to a universal fit than the printed prototypes, too.

![drumBracketParts](https://github.com/user-attachments/assets/1f792c37-387c-4307-ad32-f42957ae3051)
![drumBracketAssembled](https://github.com/user-attachments/assets/cf3dc659-a84e-4dcf-82a1-357d19f53589)

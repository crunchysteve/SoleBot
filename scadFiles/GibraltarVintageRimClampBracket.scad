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

use <solenoids.scad>

$fn = 30;
print = true;

//  If print is "false" show the solenoid, otherwise don't.
if(!print) translate([0,11,0]) rotate([0,0,-90]) solenoid();

arm() ;

module arm() difference(){
    armProfile();
    for(y=[-6,6]) for(z=[6,20.5]){
        translate([24,y,z]) rotate([0,90,0]) cylinder(r=1.8,h=10);
        translate([30,y,z]) rotate([0,90,0]) cylinder(r=3,h=15);
    }
}

module armProfile() linear_extrude(height=27) difference(){
    union(){
        offset(2.4) offset(-2.4) offset(-2.4) offset(2.4) union(){
            polygon([[25,0],[25,-11],[30,-11],
                     [30,-8],[35,-3],[160,-3],[160,0]]);
            mirror([0,1,0]) polygon([[25,0],[25,-11],[30,-11],
                                     [30,-8],[34,-3],[160,-3],[160,0]]);
            translate([160,0]) circle(8);
        }
        translate([25,-11]) square([2.4,22]);
    }
    translate([160,0]) circle(3.3);
}
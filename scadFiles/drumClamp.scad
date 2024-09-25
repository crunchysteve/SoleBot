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

use <solenoid.scad>
use <beaters.scad>

arm();
//translate([0,17,4]) snareSolenoid();

module arm(){
    translate([0,17]) difference(){
        linear_extrude(height=12) difference(){
            offset(6) offset(-6)square([140,27]);
            translate([17,20.5]) circle(2);
            translate([5,6]) circle(2);
            for(x=[65,115]) for(y=[6.5,20]) 
                    translate([x,y]) circle(1.5);
        }
        translate([-1,-1,4]) cube([23,29,9]);
        for(x=[27,77]) translate([x,4,4]) cube([45,19,9]);
    }
    difference(){
        union(){
            translate([114,1,0]) cube([6,17,12]);
            translate([120,8,0]) cube([10,12,12]);
            translate([129,-16,0]) cube([17,40,12]);
            translate([122,-25,0]) cube([5,12,12]);
            translate([124,-25,0]) cube([22,8,12]);
        }
        translate([113,1,4]) 
                rotate([0,0,45]) cube([9,9,146],center=true);
        translate([121,4,6]) rotate([0,90,0]) cylinder(r=1.7,h=40);
        translate([138,4,6]) cube([3,8,16],center=true);
        translate([138,-26,6]) rotate([-90,0,0]) cylinder(r=1.7,h=40);
        translate([138,-7,6]) cube([8,3,16],center=true);
        translate([146,24,6]) 
                rotate([0,0,45]) cube([9,9,146],center=true);
    }
}

module snareSolenoid(state=false) translate([0,0,25]) rotate([-90,0,0]){
    value = state ? -11 : -4;
    solenoid();
    translate([11,12.5,value]) mirror([0,0,1]) rotate([0,-10,0]) stickTip();
}

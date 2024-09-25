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

use <drumClamp.scad>

//  Currently, all dimensions are solely for my tiny "kiddy kit."
//  I cheat and reuse the drumClamp bracket for the solenoid mount here.

translate([-2,0,0]) base();
translate([0,0,6]) riser();

module riser() translate([-2,0,0]) difference(){
    union(){
        hull(){
            translate([0,0,0]) 
                    scale([sqrt(2),sqrt(2),1]) cylinder(r=20,h=6);
            translate([-10,-10,139.5]) 
                    scale([sqrt(2),1,1]) sphere(10);
        }
        translate([28.465,-16.5,221.5]) rotate([0,3.3,0])
                rotate([270,0,0]) rotate([0,0,90]) arm();
    }
    translate([6.1,-31,-1]) cube([46,62,130]);
    for(y=[-15,15]) translate([-6,y,-1]) cylinder(r=3,h=30);
    translate([-20,0,-1]) cylinder(r=3,h=30);
}

module base() difference(){
    union(){
        translate([61,0,0]) cylinder(r=13,h=13);
        hull(){
            translate([0,0,0]) 
                    scale([sqrt(2),sqrt(2),1]) cylinder(r=20,h=6);
            translate([61,0,0]) cylinder(r=13,h=6);
        }
    }
    for(y=[-15,15]) translate([-6,y,-1]){
        cylinder(r=3.3,h=8);
        cylinder(r=6,h=4);
    }
    translate([-20,0,-1]){
        cylinder(r=3.3,h=30);
        cylinder(r=6,h=4);
    }
}
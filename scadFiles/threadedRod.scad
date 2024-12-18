use <ISOThreadUM2.scad>
use <GibraltarVintageRimClampBracket.scad>
use <solenoid.scad>

$fn = 30;

color("slategray") translate([-160,0,123]) arm();
translate([-160,11,123]) rotate([0,0,-90]) solenoid();

color("silver"){
    for(z=[116.95,120,150,153.1]) translate([0,0,z]) hex_nut(6);
    difference(){
        translate([0,0,-0.6]) union(){
            cylinder(r=2.60,h=160);
            thread_out(6,160);
        }
        translate([0,0,-3]) cylinder(r=3.5,h=3);
        translate([0,0,158.5]) cylinder(r=3.5,h=3);
    }
}

use <solenoid.scad>

$fn = 30;

//translate([0,11,0]) rotate([0,0,-90]) solenoid();

arm() ;

module arm() difference(){
    armProfile();
    translate([24,-6,6]) rotate([0,90,0]) cylinder(r=2,h=10);
    translate([30,-6,6]) rotate([0,90,0]) cylinder(r=3,h=15);
    translate([24,6,20.5]) rotate([0,90,0]) cylinder(r=2,h=10);
    translate([30,6,20.5]) rotate([0,90,0]) cylinder(r=3,h=10);
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
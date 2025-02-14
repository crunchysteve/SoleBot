use <hexagonalprism.scad>
use <solenoids.scad>

assembled = true;     //  false for printing, true for assembled

/*  DESIGN NOTES
    ------------
    This has been designed for a 7/8" diameter hi-hat stand. I'll be
    making parts parametric at a later stage, when at a release stage.
    When slicing, use normal supports everywhere to ensure the top
    clamping piece can be separated from the main bracket. Some cleanup
    may be necessary, but it will prevent adhesion between the parts.
    Mount with solenoid bracket pointing down.
    A special bottom clutch and lifting linkage will be added soon.
*/

if(assembled){
    openerBrkt();   //  false for hex nuts, true for heat insert
    translate([18.75,-16,39]) rotate([0,0,180]) solenoid(type="JF1250B");
} else {
    translate([0,0,16]) rotate([90,0,0]) openerBrkt();
}

module openerBrkt(insertNut=false) difference(){
    union(){
        linear_extrude(height=22.2) difference(){
            offset(2) offset(-2) square([44,32],center=true);
            square([46,0.6],center=true);
            circle(11.1125);
        }
        hull() for(x=[-20,20]) 
                translate([x,-13.6,0]) cylinder(r=2.4,h=77);
    }
    for(x=[-14.5,14.5]){
        translate([x,17,11.1]) rotate([90,0,0]) cylinder(r=3.2,h=34);
        translate([x,17,11.1]) rotate([90,0,0]) cylinder(r=5.7,h=7);
        if(!insertNut){
            translate([x,-17,11.1]) rotate([-90,0,0]) 
                    rotate([0,0,30]) hexPrism(r=6.6,h=7);
        } else {
            translate([x,-17,11.1]) rotate([-90,0,0]) cylinder(r=4,h=10);
        }
    }
    for(x=[-11,11]) for(z=[46.5,69.5]){
        translate([x,0,z]) rotate([90,0,0]) cylinder(r=2,h=22);
    }
}
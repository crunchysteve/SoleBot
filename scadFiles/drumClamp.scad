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

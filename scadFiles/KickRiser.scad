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
            translate([-10,6,139.5]) 
                    scale([sqrt(2),1,1]) sphere(10);
        }
        translate([23.1,0,221.5]) rotate([0,0,0])
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
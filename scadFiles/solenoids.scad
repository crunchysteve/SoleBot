solenoid(position=0,type="JF1250B"); //  show JF-1250B module
translate([60,0,0]) solenoid(position=0,type="JF0826B");
                                      //  show JF-0826B (default) module
translate([0,70,0]) solenoid(position=1,type="JF0826B");
//                                      //  show JF-0826B activated

module solenoid(position=0,type="JF0826B"){
    if(type=="JF0826B"){
        location = 12 - position * 10;
        color("silver") 
        difference(){
            cube([22,25,27]);
            translate([-1,2,2]) cube([24,21,22]);
            translate([4,-1,26]) cube([14,27,2]);
            translate([-1,2,26]) cube([24,21,2]);
            translate([11,12.5,-1]) cylinder(r=2,h=4);
            translate([11,12.5,3]) cylinder(r=4,h=27);
            translate([5,12.5,20.5]) 
                    rotate([-90,0,0]) cylinder(r=1.5,h=15);
            translate([17,12.5,6]) 
                    rotate([-90,0,0]) cylinder(r=1.5,h=15);
        }
        color("blue") translate([11,12.5,2]) difference(){
            cylinder(r=11,h=22);
            translate([0,0,-1]) cylinder(r=4,h=29);
        }
        color("silver") translate([11,12.5,location]) difference(){
        union(){
                cylinder(r=3.75,h=35);
                translate([0,0,26]) cylinder(r=6,h=1);
                translate([0,0,-15]) cylinder(r=1.7,h=16);
                translate([0,0,-15]) cylinder(r=3,h=3);
                translate([0,0,-15]) sphere(3);
            }
            translate([-5,-1.2,28]) cube([10,2.4,10]);
            translate([0,5,31]) rotate([90,0,0]) cylinder(r=1.25,h=10);
        }
    }
    if(type=="JF1250B"){
        location = 44 - position * 10;
        color("silver") 
        difference(){
            cube([37.2,41.2,54.9]);
            translate([-1,2.5,2.5]) cube([39,36.2,47.4]);
            translate([6,-1,52.4]) cube([25.2,44,2.6]);
            translate([-1,2.5,52.4]) cube([39,36.2,2.6]);
            translate([18.6,20.6,-1]) cylinder(r=2,h=4);
            for(x=[7.7,29.5]) for(z=[7.7,31]) translate([x,-1,z]) 
                    rotate([-90,0,0]) cylinder(r=1.5,h=15);
        }
        color("darkblue") translate([18.5,20.5,2.5]) difference(){
            cylinder(r=18.5,h=47.4);
            translate([0,0,-1]) cylinder(r=6,h=29);
        }
        color("silver") translate([18.6,20.6,location]) difference(){
        union(){
                cylinder(r=6,h=35);
                translate([0,0,20]) cylinder(r=8,h=1);
                translate([0,0,-48]) cylinder(r=1.7,h=34);
                translate([0,0,-47]) cylinder(r=3,h=3);
                translate([0,0,-47]) sphere(3);
            }
            translate([-7,-1.5,23]) cube([14,3,13]);
            translate([0,15,30]) rotate([90,0,0]) cylinder(r=1.8,h=30);
        }
    }
}
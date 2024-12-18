solenoid();

module solenoid(pos=false,type="JF0826B",_echo=false){
    position = pos ? 1 : 0;
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
        if(_echo){
            echo("position",position);
            echo("type",type);
            echo("throw (mm)",10);
            echo("width (Xmm)",22);
            echo("depth (Ymm)",25);
            echo("height (Zmm)",27);
            echo("HOA (Zmm, nut to top of shaft)",55);
            echo("mount holes (Dmm)",3);
            echo("mount apacing (XxZmm)",
                 "12x12 at...\n\t5 from vertical edge,\n\t6 from bottom edge.");
        }
    }
}
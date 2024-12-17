axis();
translate([0,0,128]) btmClutch();

translate([0,0,111]) mirror([0,0,1]){
    translate([26,0,40]){
        color("silver") difference(){
            cube([38,30,64],center=true);
            cube([33,32,59],center=true);
        }
        color("blue") translate([0,0,-29.5]) cylinder(r=15,h=59);
    }
    translate([0,0,-18]) difference(){
        union(){
            translate([26,0,0.5]){
                color("lightgray"){
                    cylinder(r=2.5,h=110);
                    cylinder(r=4,h=5);
                    translate([0,0,26]) cylinder(r=7.5,h=84);
                    translate([0,0,96]) cylinder(r=12,h=1);
                }
            }
            color("black") translate([26,0,5.5]) cylinder(r=7.5,h=2.5);
        }
        translate([26,0,110]) cube([5.5,15,23],center=true);
        translate([15,0,104]) rotate([0,90,0]) cylinder(r=2.2,h=20);
    }
}

module btmClutch(){
    color("gray") difference(){     //  printed lifting flange
        hull(){
            cylinder(r=15,h=25);
            cylinder(r=30,h=10);
        }
        translate([0,0,-1]) cylinder(r=4.75,h=27);
    }
    color("white") difference(){     //  9.5mm threaded tube
        cylinder(r=4.75,h=50);
        translate([0,0,-1]) cylinder(r=3.5,h=52);
    }
}

module axis() color("lightgray") cylinder(r=3,h=300);

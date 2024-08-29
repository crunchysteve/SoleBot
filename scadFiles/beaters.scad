translate([0,21,0]) stickTip();
kickBeater();

module kickBeater() difference(){
    $fn=60;
    union(){
        cylinder(r=16,h=10);
        translate([0,0,10]) scale([1,1,0.33]) sphere(16);
    }
    translate([0,0,-1]) cylinder(r=1.5,h=5);
}

module stickTip() difference(){
    $fn=60;
    translate([0,0,3]) scale([2,1,1]) sphere(4);
    translate([0,0,-2]) cylinder(r=8,h=2);
    rotate([0,10,0]) translate([0,0,-2]) cylinder(r=1.5,h=6);
}
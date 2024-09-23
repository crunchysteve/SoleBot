use <solenoid.scad>
use <beaters.scad>

show = "parts";

module arm() color("silver") linear_extrude(height=3) difference(){
    offset(3) offset(-3){ /* arm profile from 150x50x3 aluminium */
        polygon([[0,50],[150,50],[150,0],[130,0],[130,14],
                 [120,14],[120,7],[118,3],[110,15],[110,23],[0,23]]);
        }
    //  solenoid mounting holes (can be mounted on either arm face)
    for(x=[5,17]) for(y=[29,43.5]) translate([x,y]) circle(2);
    //  mosfet board mounting holes (mount on same face as solenoid)
    for(y=[29.5,43]) translate([90,y]) circle(1.5);
    //  riser clamping bolt holes
    for(y=[10,40]) translate([140,y]) circle(2.5);
}

module riser() color("lightgray"){
    linear_extrude(height=3) difference(){
        offset(3) offset(-3){
            polygon([[0,0],[40,0],[40,200],[20,200],[20,10],
                     [10,10],[10,20],[8,20],[0,12]]);
        }
        hull() for(y=[100,190]) translate([30,y]) circle(2.5);
    }
}

if(show == "assembled"){
    translate([110,6,0]) rotate([90,0,0]) riser();
    translate([0,3,130]) rotate([90,0,0]) arm();
    translate([110,0,0]) rotate([90,0,0]) riser();
    translate([0,-25,153]) solenoid();
    translate([11,-12.5,151]) rotate([0,0,90]) mirror([0,0,1]) stickTip();
} else {
    arm();
    translate([0,-20,0]) rotate([0,0,-90]) riser();
    color("black"){
        translate([0,-61,0]) rotate([90,0,0]) cylinder(r=0.5,h=15);
        translate([100,-61,0]) rotate([90,0,0]) cylinder(r=0.5,h=15);
        translate([190,-61,0]) rotate([90,0,0]) cylinder(r=0.5,h=15);
        translate([-1,-60,0]) rotate([0,-90,0]) cylinder(r=0.5,h=15);
        translate([-1,-20,0]) rotate([0,-90,0]) cylinder(r=0.5,h=15);
        translate([201,-60,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([201,-50,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([201,-40,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([0,-70,0]) 
                text(text="<----------------------------- 100mm ---------------------------->",size=3);
        translate([100,-70,0]) 
                text(text="<-------------------------- 90mm ------------------------->",size=3);
        translate([-12,-20.3,0]) rotate([0,0,-90]) 
                text(text="<------------ 40mm --->",size=3);
        translate([14,-30.3,0]) 
                rotate([0,0,-90]) text(text="<10>",size=3);
        translate([-16,-38,0]) 
                text(text="10mm ->        <-",size=3);
        translate([-3.5,-28,0]) 
                text(text="->               <-18mm",size=3);
        translate([210,-40.3,0]) 
                rotate([0,0,-90]) text(text="<10>",size=3);
        translate([210,-50.3,0]) 
                rotate([0,0,-90]) text(text="<10>",size=3);
        translate([10.5,-4.7,0]) rotate([0,0,-90]) 
                text(text="10mm->        <-",size=3);
        translate([45,-23.5,0]) rotate([0,0,-90]) 
                text(text="20mm ->                 <-",size=3);
        translate([100,-23.7,0]) rotate([0,0,-90]) 
                text(text="10mm ->        <-",size=3);
        translate([188,-23.7,0]) rotate([0,0,-90]) 
                text(text="10mm ->        <-",size=3);
        
        translate([151,0,0]) rotate([0,90,0]) cylinder(r=0.5,h=25);
        translate([151,10,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([151,40,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([151,50,0]) rotate([0,90,0]) cylinder(r=0.5,h=25);
        translate([-16,0,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([-16,23,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([-16,29,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([-16,43.5,0]) rotate([0,90,0]) cylinder(r=0.5,h=15);
        translate([-12,23,0]) 
                rotate([0,0,-90]) text(text="<-  23mm ->",size=3);
        translate([-12,43.75,0]) 
                rotate([0,0,-90]) text(text="< 14.5 >",size=3);
        translate([116,7,0]) 
                rotate([0,0,-90]) text(text="<7>",size=3);
        translate([125,13.5,0]) 
                rotate([0,0,-90]) text(text="<-14 ->",size=3);
        translate([162.5,10,0]) 
                rotate([0,0,-90]) text(text="<10>",size=3);
        translate([162.5,40,0]) 
                rotate([0,0,-90]) text(text="<---- 30mm ---->",size=3);
        translate([162.5,50,0]) 
                rotate([0,0,-90]) text(text="<10>",size=3);
        translate([172.5,50,0]) rotate([0,0,-90]) 
                text(text="<----------- 50mm ----------->",size=3);
        
        translate([0,51,0]) rotate([-90,0,0]) cylinder(r=0.5,h=25);
        translate([5,51,0]) rotate([-90,0,0]) cylinder(r=0.5,h=15);
        translate([17,51,0]) rotate([-90,0,0]) cylinder(r=0.5,h=7);
        translate([90,51,0]) rotate([-90,0,0]) cylinder(r=0.5,h=20);
        translate([140,51,0]) rotate([-90,0,0]) cylinder(r=0.5,h=20);
        translate([150,51,0]) rotate([-90,0,0]) cylinder(r=0.5,h=25);
        translate([0,-5,0]) 
                text(text="<------------------------------------ 120mm ----------------------------------->",size=3);
        translate([0,18,0]) 
                text(text="<--------------------------------- 110mm -------------------------------->",size=3);
        translate([0,72.5,0]) 
                text(text="<----------------------------------------------- 150mm ---------------------------------------------->",size=3);
        translate([-2,60,0]) text(text=">    <- 5mm",size=3);
        translate([3,52.5,0]) text(text=">          <- 12mm",size=3);
        translate([0,68,0]) 
                text(text="<------------------------- 90mm -------------------------->",size=3);
        translate([140,68,0]) text(text="<10>",size=3);
        translate([120,-5,0]) text(text="<10> < 20mm >",size=3);
        
        translate([30,80,0]) text(text="Beater Arm",size=7);
        translate([30,-20,0]) text(text="Riser (2x)",size=7);
        translate([30,-84,0]) 
            text(text="Cut beater arm from 50mmx3mm aluminium flatbar",size=4);
        translate([30,-90,0]) 
            text(text="Cut risers from 40mmx3mm aluminium flatbar",size=4);
    }
}
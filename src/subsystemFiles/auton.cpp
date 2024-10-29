#include "main.h"
#include "subsystemHeaders/global.hpp"

//chassis.waitUntilDone();

void positiveBlue(){
    chassis.setPose(50.932,-58.899,90);
    chassis.moveToPoint(23, -58.899, 1000, {.forwards = false}); //move forward until align with ring
    chassis.moveToPoint(7.581, -50.932, 1000,{.forwards = false, .maxSpeed = 70}); //move toward until mogo
    chassis.turnToPoint(4.246,-49.45, 600, {.forwards = false});
    chassis.moveToPoint(2.949,-48.895, 800, {.forwards =false, .maxSpeed=60});
    pros::delay(400);
    clamp.set_value(true);
    pros::delay(200);
    twoStage.move(127);
    intake.move(127);
    chassis.turnToPoint(23.396,-44.404, 600);
    chassis.moveToPoint(23.097, -45.904, 1000,{.maxSpeed=80});
    pros::delay(1000);
    twoStage.brake();
    intake.brake();  //stop intake
    clamp.set_value(false);
    chassis.turnToPoint(23.396, -27.298, 600, {.forwards= false});
    chassis.moveToPoint(23.396, -23.696, 1000, {.forwards=false, .maxSpeed=75});
    pros::delay(1000);
    clamp.set_value(true);
    pros::delay(200);
    twoStage.move(127);
    intake.move(127);
    pros::delay(700);
    chassis.moveToPoint(14.393, -10.342, 1000, {.forwards =false, .maxSpeed=70});
    pros::delay(500);
    twoStage.brake();
    intake.brake();  //stop intake
    lift.move(-100);
    pros::delay(100);
    lift.brake();
}

void positiveRed(){
      chassis.setPose(-50.932,-58.899,270);
    chassis.moveToPoint(-23, -58.899, 1000, {.forwards = false}); //move forward until align with ring
    chassis.moveToPoint(-7.581, -50.932, 1000,{.forwards = false, .maxSpeed = 70}); //move toward until mogo
    chassis.turnToPoint(-4.246,-49.45, 600, {.forwards = false});
    chassis.moveToPoint(-2.949,-48.895, 800, {.forwards =false, .maxSpeed=60});
    pros::delay(400);
    clamp.set_value(true);
    pros::delay(200);
    twoStage.move(127);
    intake.move(127);
    chassis.turnToPoint(-23.396,-44.404, 600);
    chassis.moveToPoint(-23.097, -45.904, 1000,{.maxSpeed=80});
    pros::delay(1000);
    twoStage.brake();
    intake.brake();  //stop intake
    clamp.set_value(false);
    chassis.turnToPoint(-19.819, -27.298, 600, {.forwards= false});
    chassis.moveToPoint(-19.819, -23.696, 1000, {.forwards=false, .maxSpeed=75});
    pros::delay(1000);
    clamp.set_value(true);
    pros::delay(200);
    twoStage.move(127);
    intake.move(127);
    pros::delay(1500);
    chassis.moveToPoint(-14.393, -10.342, 1000, {.forwards =false, .maxSpeed=70});
    pros::delay(500);
    twoStage.brake();
    intake.brake();  //stop intake
    lift.move(-100);
    pros::delay(100);
    lift.brake();
    /*
        chassis.setPose(-51,-59, 270); //Start
    clamp.set_value(true);  // open mogo mech
    chassis.moveToPoint(-23.821, -59, 1000, {.forwards = false, .maxSpeed = 90}); //move forward until align with ring
    chassis.moveToPoint(-3.313, -48.605, 1500, {.forwards = false, .maxSpeed = 75}); //move toward until mogo
    pros::delay(1000); //wait 1 seconds
    clamp.set_value(false); // close mogo mech
    intake.move(127); //spin intake
    twoStage.move(127);
    pros::delay(800); // wait .8 seconds
    chassis.moveToPoint(-17, -58.899,1000, {.maxSpeed=60}); //move back to align with ring
    chassis.turnToHeading(0, 600); //turn the robot so  intake face ring
    clamp.set_value(true); // release mogo
    intake.move(-127); //spin intake
    chassis.moveToPoint(-18.543,-42.781,1000, {.maxSpeed=70}); //move forward to intake ring
    pros::delay(1000); //stop for 1 second
    twoStage.brake();
    intake.brake();  //stop intake
    chassis.turnToPoint(-22.469,-23.848,600, {.forwards = false, .maxSpeed = 70}); //turn to face mogo
    chassis.moveToPoint(-21, -18.5, 1000, {.forwards = false, .maxSpeed = 80}); //move toward mogo
    pros::delay(800); //stop for .8 second
    clamp.set_value(false); // clamp mogo
    twoStage.move(127);
    intake.move(127); //spin intake to collect ring
    pros::delay(1500);
    twoStage.brake();
    intake.brake(); //stop intake after 2 seconds
    //chassis.moveToPoint(-13.558, -10.907, 1000, {.forwards=false, .maxSpeed=60});
    */
}

void negativeBlueMatch(){
    chassis.setPose(58, 12.93, 0); // Starting 
    chassis.turnToPoint(68.933, -0.356, 600, {.forwards= false}); //turn to face alliance wall stake
    chassis.moveToPoint(61.933, 2.9, 600, {.forwards= false, .maxSpeed=50}); //move closer to alliance wall stake
    chassis.turnToPoint(68, 1.3, 600, {.forwards = false}); //turn to adjust to aline with the wall stake
    chassis.moveToPoint(62.75,0,500, {.forwards= false, .maxSpeed=60}); //move closer to wall stake
    pros::delay(1000);
    intake.move(-127); // start intake
    pros::delay(1000);
    intake.brake(); // stop intake
    chassis.moveToPoint(58.558,23.728,1000, {.maxSpeed=80});  //move to align with mogo
    chassis.turnToPoint(27.567,24.267, 600, {.forwards=false}); // turn toward mogo
    clamp.set_value(true); // open mogo mech
    chassis.moveToPoint(30,24.267,1000, {.forwards=false, .maxSpeed=60, }); //move toward mogo
    pros::delay(1000);
    clamp.set_value(false); //clamp mogo
    chassis.turnToPoint(22.694, 38.58, 600); //turn to angle better for middle rings
    intake.move(-127); // start intake
    chassis.moveToPoint(22.694, 38.58, 1000, {.maxSpeed=50}); //move to the right
    chassis.turnToPoint(9.599, 42.234, 600); //turn to face middle ring
    chassis.moveToPoint(13, 42.234, 600, {.maxSpeed=50}); // move toward middle rings
    chassis.moveToPoint(27.912, 22.048, 1000, {.forwards=false, .maxSpeed=60}); //move back
    chassis.turnToPoint(27.608, 47.107, 600); //turn toward ring stack
    chassis.moveToPoint(27.608, 47.107, 1000, {.maxSpeed=60}); //move and collect 1 ring
     pros::delay(1900);
    intake.brake();
    chassis.moveToPoint(15.081, 2.34, 1000, {.forwards=false, .maxSpeed=70}); //touch ladder
}

void negativeRedMatch(){
    chassis.setPose(-58, 12.93, 0); // Starting 
    chassis.turnToPoint(-68.933, -0.356, 600, {.forwards= false}); //turn to face alliance wall stake
    chassis.moveToPoint(-61.933, 2.9, 600, {.forwards= false, .maxSpeed=50}); //move closer to alliance wall stake
    chassis.turnToPoint(-68, 1.3, 600, {.forwards = false});  //turn to adjust to aline with the wall stake
    chassis.moveToPoint(-66.1,1.35,500, {.forwards= false, .maxSpeed=60}); //move closer to wall stake
    pros::delay(1000);
    intake.move(-127); // start intake
    pros::delay(1000);
    intake.brake(); // stop intake
    chassis.moveToPoint(-58.558,23.728,1000, {.maxSpeed=80}); //move to align with mogo
    chassis.turnToPoint(-27.567,24.267, 600, {.forwards=false}); // turn toward mogo
    clamp.set_value(true); // open mogo mech
    chassis.moveToPoint(-30,24.267,1000, {.forwards=false, .maxSpeed=60, }); //move toward mogo
    pros::delay(1000);
    clamp.set_value(false); //clamp mogo
    chassis.turnToPoint(-22.694, 38.58, 600); //turn to angle better for middle rings
    intake.move(-127); // start intake
    chassis.moveToPoint(-22.694, 38.58, 1000, {.maxSpeed=50});  //move to the right
    chassis.turnToPoint(-9.599, 42.234, 600); //turn to face middle ring
    chassis.moveToPoint(-18.599, 42.234, 600, {.maxSpeed=50}); // move toward middle rings
    chassis.moveToPoint(-27.912, 22.048, 1000, {.forwards=false, .maxSpeed=60}); //move back
    chassis.turnToPoint(-27.608, 47.107, 600); //turn toward ring stack
    chassis.moveToPoint(-27.608, 47.107, 1000, {.maxSpeed=60}); //move and collect 1 ring
    pros::delay(1900);
    intake.brake();
    chassis.moveToPoint(-15.081, 2.34, 1000, {.forwards=false, .maxSpeed=70}); //touch ladder
}

void skills(){
    chassis.setPose(-62.634, -0.356, 90);
    intake.move(-127);
    pros::delay(800);
    chassis.moveToPoint(-47.072, 0.2, 800, {.maxSpeed = 60});
    chassis.turnToPoint(-47.072, 22.8, 600, {.forwards=false});
    clamp.set_value(true);
    chassis.moveToPoint(-47.072, 22.8, 1000, {.forwards=false, .maxSpeed = 60});
    pros::delay(400);
    clamp.set_value(false);
    chassis.turnToPoint(-22.987, 23.728, 600);
    chassis.moveToPoint(-22.987, 23.728, 1000, {.maxSpeed = 60});
    chassis.turnToPoint(-23.358, 46.886, 600);
    chassis.moveToPoint(-23.358, 46.886, 1000, {.maxSpeed = 60});
    chassis.turnToPoint(-47.072, 62.558, 600);
    chassis.moveToPoint(-47.072, 62.558, 1000, {.maxSpeed=60});
    pros::delay(600);
    chassis.moveToPoint(-23.358, 46.886, 1000, {.forwards=false,.maxSpeed = 60});
    chassis.turnToPoint(-47.072, 47.442, 600);
    chassis.moveToPoint(-60.781, 47.442, 1200, {.maxSpeed=60});
    chassis.turnToPoint(-66.154, 65.227, 600, {.forwards = false});
    chassis.moveToPoint(-59.669, 58.187, 800, {.forwards = false, .maxSpeed= 60});
    clamp.set_value(true);
    chassis.moveToPoint(-47.072, 23.543, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.turnToPoint(-47.072, -23.328, 600, {.forwards = false});
    chassis.moveToPoint(-47.072, -23.328, 1000, {.forwards = false, .maxSpeed = 60});
    clamp.set_value(false);
    chassis.turnToPoint(-23.543, -23.884, 600);
    chassis.moveToPoint(-23.543, -23.884, 1000, {.maxSpeed = 60});
    pros::delay(300);
    chassis.turnToPoint(-23.173, -47.042, 600);
    chassis.moveToPoint(-23.173, -47.042, 1000, {.maxSpeed = 60});
    pros::delay(300);
    chassis.turnToPoint(-46.516, -62.048, 600);
    chassis.moveToPoint(-46.516, -62.048, 1000, {.maxSpeed = 60});
    pros::delay(300);
    chassis.moveToPoint(-23.543, -47.227, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.turnToPoint(-47.072, -47.227, 600);
    chassis.moveToPoint(-61.337, -47.227, 1000, {.maxSpeed=60});
    chassis.turnToPoint(-65.598,-64.457, 600, {.forwards = false});
    chassis.moveToPoint(-62.819, -57.972, 600, {.forwards=false, .maxSpeed=60});
    clamp.set_value(true);
}

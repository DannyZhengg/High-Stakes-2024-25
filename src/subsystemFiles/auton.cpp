#include "subsystemHeaders/auton.hpp"
#include "main.h"
#include "subsystemHeaders/global.hpp"
#include "subsystemHeaders/intake.hpp"

void positiveBlueAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(53.637, -8.238, 180);
    chassis.moveToPoint(53.637, 5.291, 1000, {.forwards=false, .maxSpeed=70});
    chassis.turnToHeading(270,600);
    chassis.moveToPoint(62.5, 5.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(500);
    intake.brake();
    chassis.moveToPoint(54.538,-23.571, 800);
    chassis.turnToPoint(25.676,-23.571, 600, {.forwards=false});
    chassis.moveToPoint(24.676,-23.571,1000, {.forwards=false, .maxSpeed=70});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.moveToPoint(28.682,-49.924,1000, {.maxSpeed=90});
    chassis.waitUntilDone();
    chassis.moveToPoint(35.898, -20.865, 1000, {.forwards=false});
    intake.move(-127);
    chassis.turnToPoint(70.774,-71.375, 600);
    chassis.moveToPoint(70.774,-71.375,1500);
}

void positiveRedAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-53.637, -8.238, 180);
    chassis.moveToPoint(-53.637, 5.291, 1000, {.forwards=false, .maxSpeed=70});
    chassis.turnToHeading(90,600);
    chassis.moveToPoint(-58.1, 5.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(500);
    intake.brake();
    chassis.moveToPoint(-47.082, -0.421, 800);
    chassis.turnToHeading(320,600);
    chassis.moveToPoint(-30.546, -11.545, 1000, {.forwards=false, .maxSpeed=80});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(-23.331, -47.022, 600);
    chassis.moveToPoint(-23.331, -47.022, 1000);
    chassis.waitUntilDone();
    pros::delay(1400);
    intake.brake();
    chassis.turnToPoint(-47.082, -47.022, 600);
    chassis.moveToPoint(-50.082, -47.022, 1000);
    chassis.turnToPoint(-71.135, -71.676, 600);
    intake.move(-127);
    chassis.turnToPoint(-75.54, -75.179, 600);
    chassis.moveToPoint(-75.54, -75.179, 1000);
    pros::delay(700);
    intake.move(127);
    pros::delay(1000);
    lift.move(-127);
    chassis.moveToPoint(-23.932, -23.571, 1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.moveToPoint(-15.814, -14.852, 1000,{.forwards = false} );
    chassis.waitUntilDone();
    intake.brake();
    pros::delay(500);
    lift.move(127);
}

void negativeBlueAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(53.637, 8.238, 359);
    chassis.moveToPoint(53.637, -5.291, 1000, {.forwards=false, .maxSpeed=70});
    chassis.turnToHeading(270,600);
    chassis.moveToPoint(62, -5.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(500);
    intake.brake();
    chassis.moveToPoint(47.082, 23.932, 800, {.maxSpeed=75});
    chassis.turnToPoint(28.135, 23.631, 600, {.forwards=false});
    chassis.moveToPoint(29.135, 23.631, 1000, {.forwards=false, .maxSpeed=80});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(27.54, 47.684, 600);
    chassis.moveToPoint(27.54, 47.684, 1000);
    chassis.waitUntilDone();
    chassis.turnToPoint(6.193,51.291, 600);
    chassis.moveToPoint(18.52,51.291, 1000, {.maxSpeed=60});
}

void negativeRedAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-53.637, 8.238, 359);
    chassis.moveToPoint(-53.637, -5.291, 1000, {.forwards=false, .maxSpeed=70});
    chassis.turnToHeading(90,600);
    chassis.moveToPoint(-62, -5.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(500);
    intake.brake();
    chassis.moveToPoint(-47.082, 23.932, 800, {.maxSpeed=75});
    chassis.turnToPoint(-28.135, 23.631, 600, {.forwards=false});
    chassis.moveToPoint(-29.135, 23.631, 1000, {.forwards=false, .maxSpeed=80});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(-27.54, 47.684, 600);
    chassis.moveToPoint(-27.54, 47.684, 1000);
    chassis.waitUntilDone();
    chassis.turnToPoint(-6.193,51.291, 600);
    chassis.moveToPoint(-18.52,51.291, 1000, {.maxSpeed=60});
}

void redSoloAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-45.219,40.217, 315);
    chassis.moveToPoint(-24.665,24.282,1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(100);
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(-20.925, 47.684, 600);
    chassis.moveToPoint(-20.925, 47.684, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-59.7, 11.1, 2000);
    chassis.waitUntilDone();
    clamp.set_value(false);
    twoStage.set_value(true);
    chassis.moveToPoint(-59.7, -5, 1000);
    chassis.moveToPoint(-59.7, 11.1, 800, {.forwards=false});
    chassis.turnToPoint(-53, 0.015, 600);
    chassis.moveToPoint(-53, -2.9, 800);
    chassis.waitUntilDone();
    twoStage.set_value(false);
    chassis.turnToPoint(-69,-1.5, 600, {.forwards=false});
    pros::delay(500);
    intake.brake();
    chassis.moveToPoint(-61.5,-1.5, 800, {.forwards=false});
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(1500);
    intake.brake();
    chassis.moveToPoint(-46.5,-24.8, 800, {.forwards=false});
    chassis.moveToPoint(-25.952,-23.699, 900,{.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    lift.move(-127);
    intake.move(127);
    chassis.moveToPoint(-32.358, -44.265, 800);
    chassis.waitUntilDone();
    lift.brake();
    pros::delay(800);
    chassis.moveToPoint(-12.242,-12.95, 1200, {.forwards=false});
    chassis.waitUntilDone();
    lift.move(127);
}

void blueSoloAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(45.219, 40.217, 45);
    chassis.moveToPoint(24.774,24.233, 1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(100);
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(20.925, 49.684, 600);
    chassis.moveToPoint(20.925, 49.684, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(57, 11.1, 2000);
    chassis.waitUntilDone();
    clamp.set_value(false);
    twoStage.set_value(true);
    chassis.moveToPoint(56, -5, 1000);
    chassis.moveToPoint(56, 8, 800, {.forwards=false});
    chassis.turnToPoint(47.323, 0.015, 600);
    chassis.moveToPoint(51.231, 4, 800);
    chassis.waitUntilDone();
    twoStage.set_value(false);
    chassis.turnToPoint(67.767,0.15, 600, {.forwards=false});
    pros::delay(700);
    intake.brake();
    chassis.turnToHeading(270, 600);
    chassis.moveToPoint(63.859, 2.586, 1000, {.forwards = false});
    chassis.waitUntilDone();
    /*
    intake.move(127);
    pros::delay(1500);
    intake.brake();
    chassis.moveToPoint(46.5,-24.8, 800, {.forwards=false});
    chassis.moveToPoint(25.952,-23.699, 900,{.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    lift.move(-127);
    intake.move(127);
    chassis.moveToPoint(32.358, -43.265, 800);
    chassis.waitUntilDone();
    lift.brake();
    pros::delay(800);
    chassis.moveToPoint(12.242,-12.95, 1200, {.forwards=false});
    chassis.waitUntilDone();
    lift.move(127);
    */
}

void redDoinkerRush(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-52.193, -28.682, 95);
    chassis.moveToPoint(-15.814, -35.597, 800);
    chassis.waitUntil(30);
    doinker.set_value(true);
    chassis.moveToPoint(-36.246, -36.499, 800, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(700);
    doinker.set_value(false);
    chassis.moveToPoint(-24.233,-22.97,800, {.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(-9.801,-59.349, 600);
    chassis.moveToPoint(-9.801,-59.349, 800);
    chassis.turnToPoint(-61.514, -66.865, 600);
    chassis.moveToPoint(-46.18, -65.963, 1000);
    doinker.set_value(true);
    chassis.turnToHeading(270, 600);
}

void blueDoinkerRush(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(52.193, -28.682, 225);
    chassis.moveToPoint(15.814, -35.597, 800);
    chassis.waitUntil(30);
    doinker.set_value(true);
    chassis.moveToPoint(36.246, -36.499, 800, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(700);
    doinker.set_value(false);
    chassis.moveToPoint(24.233,-22.97,800, {.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(9.801,-59.349, 600);
    chassis.moveToPoint(9.801,-59.349, 800);
    chassis.turnToPoint(61.514, -66.865, 600);
    chassis.moveToPoint(46.18, -65.963, 1000);
    doinker.set_value(true);
    chassis.turnToHeading(270, 600);
}

void redSixRings(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-45.23,28.937, 270);
    chassis.moveToPoint(-20.2,28.937, 1000,{.forwards=false, .maxSpeed=85});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(-3, 41, 1200);    
    chassis.moveToPoint(-9.599,37.159, 500,{.forwards=false});
    chassis.moveToPoint(-5.2, 59.855, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-26.044, 40.814, 1000);
    chassis.waitUntilDone();
    pros::delay(1000);
    chassis.turnToPoint(-72,72, 500);
    chassis.moveToPoint(-72,72, 1200);
    intake.move(-127);
    chassis.waitUntilDone();
    pros::delay(500);
    intake.move(127);
    pros::delay(1200);
    chassis.moveToPoint(-58.897,47.185, 800, {.forwards=false});
    chassis.waitUntilDone();
    twoStage.set_value(true);
    chassis.turnToPoint(-58.986, 0.015, 500);
    chassis.moveToPoint(-58.227, 25.276, 1400);
    chassis.waitUntilDone();
    chassis.moveToPoint(-44.663, 9.648, 1000);
    chassis.waitUntilDone();
    pros::delay(800);
    twoStage.set_value(false);
}

void blueSixRings(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(50,23.244, 91);
    chassis.moveToPoint(23.663,23.444, 800,{.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(3.69, 43.552, 1200);
    chassis.moveToPoint(7.581,41.5, 500,{.forwards=false});
    chassis.moveToPoint(4, 53.592, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(23.695, 60.448, 800);
    chassis.moveToPoint(35.185, 60, 1000);
    chassis.turnToPoint(23.699, 47.257, 500);
    chassis.moveToPoint(23.699, 47.257, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(56.12, 54.112, 800);
    chassis.waitUntilDone();
    chassis.turnToPoint(69.309,69.154, 500);
    chassis.moveToPoint(70.9,71.154, 1200);
    intake.move(-127);
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(1000);
    chassis.moveToPoint(53.897,53.185, 800, {.forwards=false});
    chassis.waitUntilDone();
    twoStage.set_value(true);
    chassis.turnToPoint(53.227, 18.276, 500);
    chassis.moveToPoint(53.227, 18.276, 1400);
    chassis.waitUntilDone();
    twoStage.set_value(false);
    chassis.moveToPoint(52.222, 25.537, 1000, {.forwards=false});
}

void skills(){
    pros::Task colorSortTask (colorSort);
    colorStart();
}

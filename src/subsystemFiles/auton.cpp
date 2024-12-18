#include "subsystemHeaders/auton.hpp"
#include "main.h"
#include "subsystemHeaders/global.hpp"
#include "subsystemHeaders/intake.hpp"

void driveForward(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    clamp.set_value(true);
    intake.move(127);
}

void red2Neg(){
    chassis.setPose(-43.402,23.608,270);
    chassis.moveToPoint(-17.389, 23.608, 1000, {.forwards=false, .maxSpeed=70});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    pros::delay(500);
    chassis.turnToPoint(-18.999, 47.361, 600);
    chassis.moveToPoint(-18.999, 50.361, 1000);
    chassis.waitUntilDone();
    lift.move(-127);
    pros::delay(900);
    chassis.moveToPoint(-11.731, 8.076, 1000, {.forwards=false});
    chassis.waitUntilDone();
    lift.move(127);
    pros::delay(800);
    lift.brake();
}

void blue2Pos(){
    chassis.setPose(43.402,-23.291, 90);
    chassis.moveToPoint(18.608,-23.291,1300, {.forwards=false, .maxSpeed=75});
    chassis.waitUntilDone();
    pros::delay(500);
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(15.081, -54.049, 600);
    chassis.moveToPoint(15.081, -54.049, 1000);
    chassis.waitUntilDone();
    lift.move(-127);
    pros::delay(700);
    lift.brake();
    chassis.moveToPoint(7.467, -10.5, 1500, {.forwards=false, .maxSpeed=80});
    chassis.waitUntil(15);
    intake.brake();
    chassis.waitUntilDone();
    lift.move(127);
    pros::delay(500);
    lift.brake();
}

void red2Pos(){
    chassis.setPose(-43.402,-23.291, 270);
    chassis.moveToPoint(-18.608,-23.291,1300, {.forwards=false, .maxSpeed=75});
    chassis.waitUntilDone();
    pros::delay(500);
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(-15.081, -54.049, 600);
    chassis.moveToPoint(-15.081, -54.049, 1000);
    chassis.waitUntilDone();
    lift.move(-127);
    pros::delay(700);
    lift.brake();
    chassis.moveToPoint(-7.467, -10.5, 1500, {.forwards=false, .maxSpeed=80});
    chassis.waitUntil(15);
    intake.brake();
    chassis.waitUntilDone();
    lift.move(127);
    pros::delay(500);
    lift.brake();
}

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
    chassis.moveToPoint(54.538,-12.571, 800);
    chassis.turnToPoint(29.676,-17.571, 600, {.forwards=false});
    chassis.moveToPoint(29.676,-17.571,1000, {.forwards=false, .maxSpeed=70});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.moveToPoint(31.682,-62.924,1000, {.maxSpeed=90});
    chassis.waitUntilDone();
    pros::delay(1200);
    chassis.turnToPoint(64, -47.323,600);
    chassis.moveToPoint(64, -47.323,1000);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.turnToPoint(76.486,-56.342,600);
    chassis.moveToPoint(76.486,-56.342,1000);
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(800);
    lift.move(-127);
    chassis.moveToPoint(12.146, -3.728, 1300, {.forwards=false});
    chassis.waitUntilDone();
    intake.brake();
    lift.move(127);
}

void positiveRedAWP(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-53.637, -8.238, 180);
    chassis.moveToPoint(-53.637, 5.291, 1000, {.forwards=false, .maxSpeed=70});
    chassis.turnToHeading(90,600);
    chassis.moveToPoint(-58.9, 5.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(500);
    intake.brake();
    chassis.moveToPoint(-47.082, -0.421, 800);
    chassis.turnToHeading(320,600);
    chassis.moveToPoint(-27.567, -14.155, 1000, {.forwards=false, .maxSpeed=80});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToPoint(-23.331, -44.022, 600);
    chassis.moveToPoint(-23.331, -44.022, 1000);
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
    chassis.moveToPoint(-14.472, -7.76, 1000,{.forwards = false} );
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
}

void redDoinkerRush(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(-52.193, -28.682, 95);
    chassis.moveToPoint(-15.814, -35.597, 800);
    chassis.waitUntilDone();
    doinker.set_value(true);
    chassis.moveToPoint(-36.246, -36.499, 800, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(700);
    doinker.set_value(false);
    pros::delay(400);
    chassis.turnToHeading(182, 600);
    chassis.moveToPoint(-33,-18, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    pros::delay(200);
    intake.move(127);
    chassis.turnToHeading(150, 600);
    pros::delay(400);
    chassis.waitUntilDone();
    clamp.set_value(false);
    chassis.moveToPoint(-23, -37, 1000);
    chassis.turnToHeading(250, 600);
    chassis.turnToHeading(187, 600);
    chassis.moveToPoint(-19, -25, 1000, {.forwards=false, .maxSpeed=70});
    intake.brake();
    chassis.waitUntilDone();
    clamp.set_value(true);
    pros::delay(300);
    intake.move(127);
    pros::delay(500);
    chassis.moveToPoint(-50, -56.5, 1200);
    chassis.waitUntilDone();
    clamp.set_value(false);
    doinker.set_value(true);
    chassis.turnToPoint(-47.984, -31.689, 600);
    chassis.waitUntilDone();
    doinker.set_value(false);
    pros::delay(500);
    chassis.moveToPoint(-41, -21, 1000, {.forwards=false});    
}

void blueDoinkerRush(){
    pros::Task colorSortTask (colorSort);
    colorStart();
    chassis.setPose(52.785, -27.404, 230);
    chassis.moveToPoint(25, -50, 795);
    chassis.waitUntilDone();
    doinker.set_value(true);
    pros::delay(300);
    chassis.moveToPoint(40, -39.556, 1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(500);
    doinker.set_value(false);
    pros::delay(500);
    chassis.turnToHeading(118, 600);
    chassis.moveToPoint(36,-34, 1000, {.forwards=false, .maxSpeed=70});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    chassis.turnToHeading(160, 600);
    chassis.moveToPoint(42,-55, 1000);
    clamp.set_value(false);
    chassis.waitUntilDone();
    intake.brake();
    chassis.turnToHeading(68, 600, {.maxSpeed=70});
    chassis.moveToPoint(26,-58, 1000, {.forwards=false, .maxSpeed=70});
    chassis.waitUntilDone();
    clamp.set_value(true);
    pros::delay(300);
    intake.move(127);
    chassis.moveToPoint(70,-54.7,1000);
    doinker.set_value(true);
    chassis.turnToPoint(54.963, -75.366, 600);
    chassis.waitUntilDone();
    chassis.moveToPoint(53.135, -64.403, 1000);
    chassis.waitUntilDone();
    clamp.set_value(false);
    chassis.moveToPoint(23.595, -23.595, 1500, {.forwards=false, .maxSpeed=70});
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
    chassis.setPose(-58.928,0.2, 90);
    intake.move(127);
    pros::delay(700);
    intake.brake();
    chassis.moveToPoint(-46.072,0.015,1000);
    chassis.turnToPoint(-47.257, 23.543, 600, {.forwards=false});
    chassis.moveToPoint(-47.257, 26.543, 1000, {.forwards=false, .maxSpeed=80});
    pros::delay(900);
    clamp.set_value(true);
    pros::delay(300);
    chassis.turnToPoint(-22.543, 24.728, 600);
    intake.move(127);
    chassis.moveToPoint(-20.543, 24.728, 1000, {.maxSpeed=80});
    chassis.turnToPoint(-0.015, 60.596, 600);
    chassis.moveToPoint(5.78, 62.078, 1500, {.maxSpeed=75});
    pros::delay(600);
    chassis.turnToPoint(-23.173, 46.257, 600);
    chassis.moveToPoint(-62.263,47.227, 4500, {.maxSpeed=40});
    chassis.turnToPoint(-47.257, 61.152, 600);
    chassis.moveToPoint(-42.225, 62.078, 1000, {.maxSpeed=70});
    chassis.turnToPoint(-66.154,65.968, 600, {.forwards=false});
    chassis.moveToPoint(-66.154,65.968, 1000, {.forwards=false, .maxSpeed=60});
    pros::delay(1200);
    clamp.set_value(false);
    intake.move(-127);
    pros::delay(300);
    intake.brake();
    chassis.moveToPoint(-56.701, 47.257, 1000);
    chassis.turnToPoint(-56.072, 0.2, 600, {.forwards = false});
    chassis.moveToPoint(-56.886, 0.015,1000, {.forwards=false, .maxSpeed=80}); //First part
    chassis.moveToPoint(-56.257, -17.543, 1000, {.forwards=false, .maxSpeed=80});
    pros::delay(900);
    clamp.set_value(true);
    pros::delay(300);
    chassis.turnToPoint(-22.543, -22.728, 600);
    intake.move(127);
    chassis.moveToPoint(-22.543, -23.728, 1000, {.maxSpeed=80});
    chassis.turnToPoint(-2.794, -59.64, 600);
    chassis.moveToPoint(-2.794, -59.64, 1500, {.maxSpeed=75});
    pros::delay(600);
    chassis.turnToPoint(-23.173, -43.257, 600);
    chassis.moveToPoint(-63.263,-43.227, 4500, {.maxSpeed=40});
    chassis.turnToPoint(-47.257, -61.152, 600);
    chassis.moveToPoint(-42.225, 62.078, 1000, {.maxSpeed=70});
    chassis.turnToPoint(-66.154,-65.968, 600, {.forwards=false});
    chassis.moveToPoint(-66.154,-65.968, 1000, {.forwards=false, .maxSpeed=60});
    pros::delay(1200);
    clamp.set_value(false);
    intake.brake();
    chassis.moveToPoint(-74.465, -74.148, 1000);
}

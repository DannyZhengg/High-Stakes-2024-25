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
}

void negativeBlueMatch(){
    chassis.setPose(53.185,17.244, 125); //around 125
    lift.move(-127);
    pros::delay(1000);
    lift.brake();
    pros::delay(500);
    lift.move(127);
    pros::delay(1000);
    lift.brake();
    chassis.moveToPoint(21.025, 24.543, 1000, {.forwards = false, .maxSpeed=80});
    pros::delay(1400);
    clamp.set_value(true);
    pros::delay(300);
    chassis.turnToPoint(19.358, 50.072, 600);
    twoStage.move(127);
    intake.move(127);
    chassis.moveToPoint(19.358, 50.072, 1000, { .maxSpeed=80});
    pros::delay(500);
    chassis.turnToPoint(6.314, 50.592, 600);
    chassis.moveToPoint(3.905,50.592, 1000, {.maxSpeed=60});
    pros::delay(300);
    chassis.moveToPoint(22.246, 43.886, 800, {.forwards=false, .maxSpeed=70});
    chassis.turnToPoint(-3.905, 43.552, 600);
    chassis.moveToPoint(3.35,43.552,1000, {.maxSpeed=60});
    chassis.moveToPoint(23,41,1000, {.forwards=false,.maxSpeed=70});
    chassis.moveToPoint(10.2, 7.7, 1000, {.maxSpeed=60});
}

void negativeRedMatch(){
    chassis.setPose(-53.185,17.244, 215);
    lift.move(-127);
    pros::delay(1000);
    lift.brake();
    pros::delay(500);
    lift.move(127);
    pros::delay(1000);
    lift.brake();
    chassis.moveToPoint(-21.025, 24.543, 1000, {.forwards = false, .maxSpeed=80});
    pros::delay(1400);
    clamp.set_value(true);
    pros::delay(300);
    chassis.turnToPoint(-19.358, 50.072, 600);
    twoStage.move(127);
    intake.move(127);
    chassis.moveToPoint(-19.358, 50.072, 1000, { .maxSpeed=80});
    pros::delay(500);
    chassis.turnToPoint(-6.314, 50.592, 600);
    chassis.moveToPoint(-3.905,50.592, 1000, {.maxSpeed=60});
    pros::delay(300);
    chassis.moveToPoint(-22.246, 43.886, 800, {.forwards=false, .maxSpeed=70});
    chassis.turnToPoint(-3.905, 43.552, 600);
    chassis.moveToPoint(-3.35,43.552,1000, {.maxSpeed=60});
    chassis.moveToPoint(-23,41,1000, {.forwards=false,.maxSpeed=70});
    chassis.moveToPoint(-10.2, 7.7, 1000, {.maxSpeed=60});
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

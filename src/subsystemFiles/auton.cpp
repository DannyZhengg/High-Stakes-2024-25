#include "main.h"
#include "subsystemHeaders/global.hpp"

void positiveBlue(){
    chassis.setPose(50.932,-58.899,90);
    chassis.moveToPoint(23, -58.899, 1000, {.forwards = false}); //move forward until align with ring
    chassis.moveToPoint(7.581, -50.932, 1000,{.forwards = false, .maxSpeed = 70}); //move toward until mogo
    chassis.turnToPoint(4.246,-49.45, 600, {.forwards = false});
    chassis.moveToPoint(2.949,-48.895, 800, {.forwards =false, .maxSpeed=60});
    pros::delay(400);
    clamp.set_value(true);
    pros::delay(200);
    intake.move(127);
    chassis.turnToPoint(23.396,-44.404, 600);
    chassis.moveToPoint(23.097, -45.904, 1000,{.maxSpeed=80});
    pros::delay(1000);
    intake.brake();  //stop intake
    clamp.set_value(false);
    chassis.turnToPoint(19.819, -27.298, 600, {.forwards= false});
    chassis.moveToPoint(19.819, -23.696, 1000, {.forwards=false, .maxSpeed=75});
    pros::delay(1000);
    clamp.set_value(true);
    pros::delay(200);
    intake.move(127);
    pros::delay(1500);
    intake.brake();
    chassis.moveToPoint(46.448, -56.942, 1000, {.maxSpeed=70});
     /*
    twoStage.set_value(true);
    chassis.turnToPoint(37.072,-.015, 600);
    chassis.moveToPoint(37.072,-.75, 1500, {.maxSpeed = 50});
    pros::delay(1500);
    twoStage.set_value(false);
    pros::delay(1000);
    chassis.moveToPoint(23.352,-23.581, 800, {.forwards=false, .maxSpeed=70});
    pros::delay(2000);
    chassis.moveToPoint(8.064,-9.13, 1000, {.forwards=false, .maxSpeed=80});
    pros::delay(1400);
    lift.move(-127);
    pros::delay(400);
    lift.brake();
    */
}

void positiveRed(){
    chassis.setPose(-50.932,-58.899,270);
    chassis.moveToPoint(-23, -58.899, 1000, {.forwards = false}); //move forward until align with ring
    chassis.moveToPoint(-7.581, -50.932, 1000,{.forwards = false, .maxSpeed = 70}); //move toward until mogo
    chassis.turnToPoint(-4.246,-49.45, 600, {.forwards = false});
    chassis.moveToPoint(-2.949,-48.895,  800, {.forwards =false, .maxSpeed=60});
    pros::delay(400);
    clamp.set_value(true);
    pros::delay(200);
    intake.move(127);
    chassis.turnToPoint(-23.396,-44.404, 600);
    chassis.moveToPoint(-23.097, -45.904, 1000,{.maxSpeed=80});
    pros::delay(1000);
    intake.brake();  //stop intake
    clamp.set_value(false);
    chassis.turnToPoint(-19.819, -27.298, 600, {.forwards= false});
    chassis.moveToPoint(-19.819, -23.696, 1000, {.forwards=false, .maxSpeed=75});
    pros::delay(1000);
    clamp.set_value(true);
    pros::delay(200);
    intake.move(127);
    pros::delay(1500);
    intake.brake();
    chassis.moveToPoint(-46.448, -56.942, 1000, {.maxSpeed=70});
    /*
    twoStage.set_value(true);
    chassis.turnToPoint(-37.072,.015, 600);
    chassis.moveToPoint(-37.072,.75, 1500, {.maxSpeed = 40});
    pros::delay(1500);
    twoStage.set_value(false);
    lift.move(-127);
    pros::delay(500);
    lift.brake();
    pros::delay(1000);
    chassis.moveToPoint(-23.352,-23.581, 800, {.forwards=false, .maxSpeed=70});
    pros::delay(1500);
    chassis.moveToPoint(-8.6,-11.9, 1000, {.forwards=false, .maxSpeed=80});
    pros::delay(800);
    lift.move(127);
    pros::delay(400);
    lift.brake();
    */
}

void negativeBlueMatch(){
    chassis.setPose(50,23.244, 91);
    chassis.moveToPoint(23.663,23.444, 800,{.forwards=false});
    chassis.waitUntilDone();
    clamp.set_value(true);
    intake.move(127);
    pros::delay(300);
    chassis.moveToPoint(3.69, 43.552, 1200);
    chassis.moveToPoint(7.581,41.5, 500,{.forwards=false});
    chassis.moveToPoint(3, 53.592, 1000);
    chassis.moveToPoint(23.695, 60.448, 800);
    chassis.moveToPoint(35.185, 60, 1000);
    chassis.turnToPoint(23.699, 47.257, 500);
    chassis.moveToPoint(23.699, 47.257, 1000);
    chassis.waitUntilDone();
    pros::delay(1300);
    chassis.moveToPoint(56.12, 54.112, 800);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.turnToPoint(69.309,69.154, 500);
    chassis.moveToPoint(70.9,71.154, 1200);
    chassis.waitUntilDone();
    intake.move(127);
    pros::delay(1000);
    chassis.moveToPoint(53.897,53.185, 800, {.forwards=false});
    chassis.waitUntilDone();
    twoStage.set_value(true);
    chassis.moveToPoint(47.227, 6.276, 1400);
    chassis.waitUntilDone();
    twoStage.set_value(false);
    
}

void negativeRedMatch(){
    chassis.setPose(-58.325, 23.455, 270);
    chassis.moveToPoint(-24.826, 23.76, 1000, {.forwards=false, .maxSpeed = 70});
    pros::delay(1000);
    clamp.set_value(true);
    pros::delay(500);
    intake.move(127);
    chassis.turnToPoint(-23.303,47.209, 600);
    chassis.moveToPoint(-23.303,47.209, 1000, {.maxSpeed = 70});
    chassis.turnToPoint(-4.117, 52.691, 600);
    chassis.moveToPoint(-10.249, 52.691, 1000, {.maxSpeed=50});
    chassis.moveToPoint(-20.562,46.295, 1000, {.forwards=false} );
    chassis.moveToPoint(-10.208, 43.555, 1000, {.maxSpeed=50});
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
    chassis.moveToPoint(-56.701, -47.257, 1000);
}

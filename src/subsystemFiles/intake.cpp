#include "main.h"
#include "pros/misc.h"
#include "subsystemHeaders/global.hpp"

void colorSort(){
    while(true){}
}

void setIntake(){
    while(true){
        intake.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)));
        pros::delay(10);
    }
}
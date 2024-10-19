#include "main.h"

bool pistonStatus = false;

void setLift(){
    while(true){
        lift.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));
        pros::delay(10);
    }
}

void openPiston(){
    while (true) {
         if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
            if(pistonStatus == false) {
                piston.set_value(true);
                pistonStatus = true;
                pros::delay(500);
        }
            else if(pistonStatus == true) {
                piston.set_value(false);
                pistonStatus = false;
                pros::delay(500);
        }
    }
}
}
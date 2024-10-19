#include "main.h"

bool wingStatus = false;

void setWing(){
    while (true) {
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
            if(wingStatus == false) {
            wing.set_value(true);
            wingStatus = true;
            pros::delay(500);
        }
        else if(wingStatus == true) {
            wing.set_value(false);
            wingStatus = false;
            pros::delay(500);
        }
    }
    }
}
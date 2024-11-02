#include "main.h"

bool doinkerStatus = false;

void setDoinker(){
    while (true) {
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
            if(doinkerStatus == false) {
            doinker.set_value(true);
            doinkerStatus = true;
            pros::delay(500);
        }
            else if(doinkerStatus == true) {
            doinker.set_value(false);
            doinkerStatus = false;
            pros::delay(500);
        }
    }
    }
}
#include "main.h"

bool clampStatus = false;

void setClamp() {
    while (true) {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
        if(clampStatus == false) {
            clamp.set_value(true);
            clampStatus = true;
            pros::delay(500);
        }
        else if(clampStatus == true) {
            clamp.set_value(false);
            clampStatus = false;
            pros::delay(500);
        }
    }
}
}
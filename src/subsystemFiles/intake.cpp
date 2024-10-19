#include "main.h"

void setIntake(){
    while(true){
        intake.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)));
        twoStage.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)));
        pros::delay(10);
    }
}

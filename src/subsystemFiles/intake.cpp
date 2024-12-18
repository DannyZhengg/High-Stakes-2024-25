#include "subsystemHeaders/intake.hpp"
#include "main.h"
#include "pros/misc.h"
#include "subsystemHeaders/global.hpp"

//220 = blue
//13 = red

const int opponentColorHue = 13;
const int colorTolerance =10;

bool colorSortStatus = false;

void colorStart(){
    colorSortStatus = true;
}

void colorStop(){
    colorSortStatus = false;
}

void colorSort(){
    while(true){
        if(colorSortStatus){
            int hue = colorSensor.get_hue();
            if (hue >= opponentColorHue - colorTolerance && hue <= opponentColorHue + colorTolerance){
                pros::delay(200);
                intake.move(-127);
                pros::delay(100);
                intake.move(127);
            }
            pros::delay(20);
        }
    }
}

void setIntake(){
    while(true){
        intake.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)));
        pros::delay(10);
    }
}
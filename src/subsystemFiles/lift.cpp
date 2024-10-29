#include "main.h"
#include "subsystemHeaders/global.hpp"

// PID Constants (tune these for your specific system)
const float Kp = 0.5;   // Proportional gain
const float Ki = 0.01;  // Integral gain
const float Kd = 0.1;   // Derivative gain

const int POSITION_TOLERANCE = 50;   // Position tolerance in centidegrees (e.g., 0.5 degrees)
const int MAX_OUTPUT = 50;          // Max motor speed (adjust if necessary)

// Target positions for the arm
const int ARM_POSITION_DOWN = 0;
const int ARM_POSITION_RIGHT = 45; // Adjust as needed
const int ARM_POSITION_UP = 90;   // Adjust as needed

// PID control function
void moveArmToPosition(int targetPosition) {
    int error = 0, lastError = 0;
    int integral = 0;
    int derivative = 0;

    while (true) {
        int currentPosition = ladyBrown.get_position();
        error = targetPosition - currentPosition;

        // Check if within tolerance range
        if (std::abs(error) <= POSITION_TOLERANCE) {
            lift.move_velocity(0);  // Stop motor
            break;
        }

        // PID Calculations
        integral += error;
        derivative = error - lastError;
        lastError = error;

        int output = (Kp * error) + (Ki * integral) + (Kd * derivative);

        // Limit the output to the max motor speed range
        output = std::clamp(output, -MAX_OUTPUT, MAX_OUTPUT);

        lift.move_velocity(output);  // Apply the PID output as motor velocity

        pros::delay(20);  // Small delay to prevent excessive loop speed
    }
}

void setLadyBrown(){
    while(true){
                // Check controller buttons to set the target position
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            moveArmToPosition(ARM_POSITION_DOWN);
        } 
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            moveArmToPosition(ARM_POSITION_RIGHT);
        } 
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            moveArmToPosition(ARM_POSITION_UP);
        }
        pros::delay(20);
    }
 }



void setLift(){
    while(true){
        lift.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));
        pros::delay(20);
    }
}


/*
enum ArmState{
    idle,
    medium,
    scoring
};

ArmState currentState = idle;

const int low_angle = 0;
const int medium_angle = 4500;
const int high_angle = 9000;

void setArmAngle(int angle){
    arm.move_absolute(angle, 100);
}

int getArmAngle(){
    return arm.get_position();
}

void updateArmState(){
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
    currentState = idle;
    } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
    currentState = medium_angle;
    } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
    currentState = high_angle;
    }
}

void correctArmAngle(){
    int targetAngle;
    switch(currentState){
        case idle:
            targetAngle = low_angle;
            break;
        case medium:
            targetAngle = medium_angle;
            break;
        case scoring:
            targetAngle = high_angle;
            break;
    }

    int currentAngle = getArmAngle();
    if(currentAngle != targetAngle){
        setArmAngle(targetAngle);
    }
}

*/


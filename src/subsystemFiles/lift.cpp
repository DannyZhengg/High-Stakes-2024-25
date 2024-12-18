#include "main.h"
#include "subsystemHeaders/global.hpp"

/*
const double BOTTOM_POSITION = 6530;
const double MIDDLE_POSITION = 9000;
const double TOP_POSITION = 24000;

void moveArmToPosition(double targetPosition){
    double currentArmPosition = ladyBrown.get_angle();
    double error = targetPosition - currentArmPosition;

    const double deadband = 10;
    if (std::abs(error) < deadband) {
        lift.move_voltage(0);
        return;
    }

    double power = armPID.update(error);

    power = std::clamp(power, -12000.0, 12000.0);

    lift.move_voltage(power);
}

void moveArmToBottom(){
    moveArmToPosition(BOTTOM_POSITION);
}


void moveArmToMiddle(){
    moveArmToPosition(MIDDLE_POSITION);
}


void moveArmToTop(){
    moveArmToPosition(TOP_POSITION);
}
*/

// PID Constants (tune these for your specific system)
const float Kp = 1.2;   // Proportional gain
const float Ki = 0;  // Integral gain
const float Kd = .95;   // Derivative gain

const int POSITION_TOLERANCE = 250;   // Position tolerance in centidegrees (e.g., 1 degrees)

// Target positions for the arm
const int ARM_POSITION_DOWN = 0;
const int ARM_POSITION_RIGHT = 11000; // Adjust as needed
const int ARM_POSITION_UP = 30000;   // Adjust as needed

// PID control function
void moveArmToPosition(int targetPosition) {
    int error = 0, lastError = 0;
    int integral = 0;
    int derivative = 0;

    while (true) {
        int currentPosition = ladyBrown.get_position();
        error = targetPosition - currentPosition;

        // pros::lcd::clear_line(4);
        // pros::lcd::print(4, "Current Position: %d", currentPosition);

        // Check if within tolerance range
        if (std::abs(error) <= POSITION_TOLERANCE) {
            lift.brake();  // Stop motor
            //  pros::lcd::print(0, "Arm reached target position");  // Confirm target reached
            break;
        }

        // PID Calculations
        integral += error;
        derivative = error - lastError;
        lastError = error;

        int output = (Kp * error) + (Ki * integral) + (Kd * derivative);

        lift.move(-output);  // Apply the PID output as motor velocity
        
        pros::delay(10);  // Small delay to prevent excessive loop speed
    }
}

void setLadyBrown(){
    while(true){
        // Check controller buttons to set the target position
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            moveArmToPosition(ARM_POSITION_DOWN);
        } 
        else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            moveArmToPosition(ARM_POSITION_RIGHT);
        } 
        else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
            moveArmToPosition(ARM_POSITION_UP);
        }
        pros::delay(10);
    }
 }

void setLift(){
    while(true){
        lift.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));
        pros::delay(20);
    }
}
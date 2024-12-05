#include "main.h"
#include "subsystemHeaders/global.hpp"

// PID Constants (tune these for your specific system)
const float Kp = 1;   // Proportional gain
const float Ki = 0;  // Integral gain
const float Kd = 0;   // Derivative gain

const int POSITION_TOLERANCE = 150;   // Position tolerance in centidegrees (e.g., 1 degrees)
const int MAX_OUTPUT = 100;          // Max motor speed (adjust if necessary)

// Target positions for the arm
const int ARM_POSITION_DOWN = 0;
const int ARM_POSITION_RIGHT = 9000; // Adjust as needed
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

        // Limit the output to the max motor speed range
        output = std::clamp(output, -MAX_OUTPUT, MAX_OUTPUT); //maybe delete this

        lift.move_velocity(-output);  // Apply the PID output as motor velocity
        
        pros::delay(20);  // Small delay to prevent excessive loop speed
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
        pros::delay(20);
    }
 }

void setLift(){
    while(true){
        lift.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));
        pros::delay(20);
    }
}

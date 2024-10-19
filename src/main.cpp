#include "main.h"

void on_center_button() {}

void initialize() {
	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
	chassis.setPose(0,0,0);
	controller.set_text(1,0, "Hi Jackson");
	driveLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	wing.set_value(false);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	driveLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

	//positiveBlue();
	positiveRed();
	//negativeBlueMatch();
	//negativeRedMatch();
	//skills();
}

/*
·▄▄▄▄  ▄▄▄  ▪   ▌ ▐·▄▄▄ .▄▄▄         
██▪ ██ ▀▄ █·██ ▪█·█▌▀▄.▀·▀▄ █·       
▐█· ▐█▌▐▀▀▄ ▐█·▐█▐█•▐▀▀▪▄▐▀▀▄        
██. ██ ▐█•█▌▐█▌ ███ ▐█▄▄▌▐█•█▌       
▀▀▀▀▀• .▀  ▀▀▀▀. ▀   ▀▀▀ .▀  ▀       
 ▄▄·        ▐ ▄ ▄▄▄▄▄▄▄▄        ▄▄▌  
▐█ ▌▪▪     •█▌▐█•██  ▀▄ █·▪     ██•  
██ ▄▄ ▄█▀▄ ▐█▐▐▌ ▐█.▪▐▀▀▄  ▄█▀▄ ██▪  
▐███▌▐█▌.▐▌██▐█▌ ▐█▌·▐█•█▌▐█▌.▐▌▐█▌▐▌
·▀▀▀  ▀█▄▀▪▀▀ █▪ ▀▀▀ .▀  ▀ ▀█▄▀▪.▀▀▀                                                                                                            
*/

void opcontrol() {
	driveLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	driveRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

	pros::Task wing(setWing);
	pros::Task intake(setIntake);
	pros::Task clamp(setClamp);
	pros::Task lift(setLift);
	pros::Task piston(openPiston);

	while (true) {
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int RightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, RightX, false, .65);

        // delay to save resources
		pros::delay(25);
	}
}
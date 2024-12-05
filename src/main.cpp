#include "main.h"
#include "subsystemHeaders/global.hpp"
#include "subsystemHeaders/intake.hpp"

void on_center_button() {}

void initialize() {
	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
	chassis.setPose(0,0,0);
	controller.set_text(1,0, "Hi Jackson");
	driveLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	ladyBrown.reset_position();
	pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
			pros::lcd::print(3, "Hue: %f", colorSensor.get_hue());
            // delay to save resources
            pros::delay(20);
        }
    });
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	colorSensor.set_led_pwm(100);
	driveLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	//positiveBlueAWP();
	//positiveRedAWP();
	//negativeBlueAWP();
	negativeRedAWP();
	//redSoloAWP();
	//blueSoloAWP();
	//redDoinkerRush();
	//blueDoinkerRush();
	//redSixRings();
	//blueSixRings();
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
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	colorStop();
	
	pros::Task doinker(setDoinker);
	pros::Task intake(setIntake);
	pros::Task clamp(setClamp);
	pros::Task lift(setLift);
	pros::Task ladyBrown(setLadyBrown);

	while (true) {
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int RightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, RightX, false, 1);

        // delay to save resources
		pros::delay(20);
	}
}
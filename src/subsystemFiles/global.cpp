#include "subsystemHeaders/global.hpp"
#include "main.h"

//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//Motors
pros::Motor intake(-3, pros::MotorGearset::green);
pros::Motor lift(1, pros::MotorGearset::red);

//Motor Groups
pros::MotorGroup driveLeft({-20,-8,-10}, pros::MotorGearset::blue);
pros::MotorGroup driveRight({6,9,7}, pros::MotorGearset::blue);

// Sensors
pros::Imu imu(21);

//ADI DIGITAL OUTPUT
pros::adi::DigitalOut clamp('D');
pros::adi::DigitalOut doinker('C');
pros::adi::DigitalOut twoStage('B');

//Sensors
pros::Rotation ladyBrown(11);
pros::Optical colorSensor(4);
pros::Distance distanceSensor(13);


// drivetrain settings
lemlib::Drivetrain drivetrain(&driveLeft, // left motor group
                              &driveRight, // right motor group
                              15, // 15 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2 (for now)
);

// odometry settings
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);
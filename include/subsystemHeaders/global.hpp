#pragma once
#include "main.h"

// Controllers
extern pros::Controller controller;

extern pros::Motor intake;
extern pros::Motor twoStage;
extern pros::Motor lift;

// Motor Groups
extern pros::MotorGroup driveLeft;
extern pros::MotorGroup driveRight;

// ADI Digital Outputs
extern pros::adi::DigitalOut clamp;
extern pros::adi::DigitalOut wing;
extern pros::adi::DigitalOut piston;

// Inertial Sensor
extern pros::Imu imu;

// LemLib chassis object
extern lemlib::Chassis chassis;
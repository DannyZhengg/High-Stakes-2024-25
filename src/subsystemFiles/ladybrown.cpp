#include "main.h"

Lift::Lift(pros::Motor& motor, pros::Rotation& rotation, lemlib::PID pid)
    : m_motor(motor), m_rotation(rotation), m_pid(pid), m_state(State::BOTTOM) {}

float Lift::getTargetAngle() const {
    switch (m_state) {
        case State::BOTTOM: return 290;
        case State::MIDDLE: return 330;
        case State::TOP: return 357.5;
        default: return NAN;
    }
}

float Lift::getSensedAngle() const { 
    return m_rotation.get_angle() / 100.0; 
}

float Lift::calcError() const { 
    return getTargetAngle() - getSensedAngle(); 
}

void Lift::update() {
    const float error = calcError();
    const float output = m_pid.update(error);
    m_motor.move_voltage(output);
}

void Lift::goToBottom() { 
    m_state = State::BOTTOM; 
}

void Lift::goToMiddle() { 
    m_state = State::MIDDLE; 
}

void Lift::goToTop() { 
    m_state = State::TOP; 
}

void Lift::goDown() {
    switch (m_state) {
        case State::BOTTOM: break;
        case State::MIDDLE: m_state = State::BOTTOM; break;
        case State::TOP: m_state = State::TOP; break;
    }
}

void Lift::goUp() {
    switch (m_state) {
        case State::BOTTOM: m_state = State::MIDDLE; break;
        case State::MIDDLE: m_state = State::TOP; break;
        case State::TOP: break;
    }
}

Lift ladyBrownArm(lift, ladyBrown, armPID); // lift motor, rotation sensor, PID controller

void liftControlTask(void* param) {
    while (true) {
        // Check if the up or down buttons are pressed
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
            ladyBrownArm.goUp();  // Move the lift up
        } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            ladyBrownArm.goDown();  // Move the lift down
        }

        // Update the lift's position based on the current state and PID
        ladyBrownArm.update();

        // Delay to save resources
        pros::delay(10);
    }
}
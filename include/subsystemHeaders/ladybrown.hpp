#pragma once
#include "main.h"

class Lift{
private:
    pros::Motor& m_motor;
    pros::Rotation& m_rotation;
    lemlib::PID m_pid;

    enum State {
        BOTTOM,
        MIDDLE,
        TOP,
    };

    State m_state;

    float getTargetAngle() const;
    float getSensedAngle() const;
    float calcError() const;

public:
    Lift(pros::Motor& motor, pros::Rotation& rotation, lemlib::PID pid);

    void goToBottom();
    void goToMiddle();
    void goToTop();

    void goDown();
    void goUp();

    void update();
};

void liftControlTask(void* param);
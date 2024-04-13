#include "../include/move.hpp"


Move:: Move(webots:: Robot *r){
    motor_names.push_back("wheel_left_joint");
    motor_names.push_back("wheel_right_joint");
    robot = r;

    for(int i = 0; i < N_MOTORS;i++){
        motors.push_back(robot->getMotor(motor_names[i]));
    }

}

void Move:: print_motor_names(){
    for(int i = 0; i < N_MOTORS; i++){
        std:: cout << motor_names[i] << std::endl;
    }
}

void Move:: forward(){
    float right_speed_increase = 0.5;
    float left_speed_increase = 0.5;
    std::cout << motors[LEFT_WHEEL]->getVelocity() << std::endl;
    motors[LEFT_WHEEL]->setVelocity(motors[LEFT_WHEEL]->getVelocity()+left_speed_increase);
    motors[RIGHT_WHEEL]->setVelocity(motors[RIGHT_WHEEL]->getVelocity()+right_speed_increase);
}

void Move:: slowDown(){
    float right_speed_decrease = -0.5;
    float left_speed_decrease = -0.5;

    std::cout << motors[LEFT_WHEEL]->getVelocity() << std::endl;
    motors[LEFT_WHEEL]->setVelocity(motors[LEFT_WHEEL]->getVelocity()-left_speed_decrease);
    motors[RIGHT_WHEEL]->setVelocity(motors[RIGHT_WHEEL]->getVelocity()-right_speed_decrease);
}

void Move:: stop(){
    float left_speed = 0.0;
    float right_speed = 0.0;
    motors[LEFT_WHEEL]->setVelocity(left_speed);
    motors[RIGHT_WHEEL]->setVelocity(right_speed);
}

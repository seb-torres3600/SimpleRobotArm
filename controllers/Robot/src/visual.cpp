#include "../include/visual.hpp"


Visual:: Visual(webots::Robot *r){
    motor_names.push_back("head_2_joint");
    motor_names.push_back("head_1_joint");
    robot = r;
    for(int i = 0; i < H_MOTORS; i++){
        motors.push_back(robot->getMotor(motor_names[i]));
    }
    time_step = robot->getBasicTimeStep();
    camera_one = robot->getCamera("Astra rgb");
    camera_one->enable(time_step);

    camera_two = robot->getCamera("Astra depth");
    camera_two->enable(time_step);
}


void Visual:: transform(int motor_index, float target_location, float duration){
    float current_position = motors[motor_index]->getTargetPosition();
    std:: cout << "Current Position: " << current_position << std::endl;
    int n_steps_to_achieve_target = duration * 1000 / time_step;
    float steps = (target_location - current_position) / n_steps_to_achieve_target;
    std:: cout << steps << std:: endl;

    for(int i = 0; i < n_steps_to_achieve_target; i++){
        current_position += steps;
        motors[motor_index]->setPosition(current_position);
        robot->step(time_step);
    }
}

void Visual:: panDown(){
    transform(0, -1.0, 1.0);
}

void Visual:: getRecognizedObjects(){
    int n_objects = camera_two->getRecognitionNumberOfObjects();
    std:: cout << n_objects << std::endl;
}
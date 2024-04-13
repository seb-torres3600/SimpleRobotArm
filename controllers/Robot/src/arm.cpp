#include "../include/arm.hpp"


Arm:: Arm(webots::Robot *r){
    motor_names.push_back("arm_1_joint");
    motor_names.push_back("arm_2_joint");
    motor_names.push_back("arm_3_joint");
    motor_names.push_back("arm_4_joint");
    motor_names.push_back("arm_5_joint");
    motor_names.push_back("arm_6_joint");
    motor_names.push_back("arm_7_joint");
    motor_names.push_back("gripper_left_finger_joint");
    motor_names.push_back("gripper_right_finger_joint");

    robot = r;
    for(int i = 0; i < N_MOTOR; i++){
        motors.push_back(robot->getMotor(motor_names[i]));
    }
    time_step = robot->getBasicTimeStep();
}

void Arm:: transform(int motor_index, float target_location, float duration){
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

void Arm:: travelMode(){
    //std:: cout << motors[0]->getTargetPosition() << std::endl;
    //motors[0]->setPosition(motors[0]->getTargetPosition() + 0.1);
    //std:: cout << motors[1]->getTargetPosition() << std::endl;
    //motors[1]->setPosition(motors[1]->getTargetPosition() + 0.01);
    std:: cout << motors[2]->getTargetPosition() << std::endl;
    motors[2]->setPosition(motors[2]->getTargetPosition() + 0.05);
    std:: cout << motors[3]->getTargetPosition() << std::endl;
    motors[3]->setPosition(motors[3]->getTargetPosition() + 0.05);
    std:: cout << motors[N_MOTOR-1]->getTargetPosition() << std::endl;
    motors[N_MOTOR-1]->setPosition(motors[N_MOTOR-1]->getTargetPosition() + 0.01);

    /*
    1.471
    0.1
    0
    1.4
    */
}

void Arm:: pickUpCan(){
    reset();
    centerArm();
    openClaws();
    rotateHand();
    dropArm();
    shoulderDown();
    closeClaws();
    transform(1, 0.5, 1.0);
    return;
}

void Arm:: centerArm(){
    double center = PI/2;
    std:: cout << "Center: " << center << std:: endl;
    transform(0, center, 2.0);
}

void Arm:: dropArm(){
    transform(3, 1.2, 2.0);
}

void Arm:: rotateHand(){
    transform(6, 1.57, 2.0);
}

void Arm:: openClaws(){
    transform(7, 0.044, 2.0);
    transform(8, 0.044, 2.0);
}

void Arm:: closeClaws(){
    transform(7, 0.02, 2.0);
    transform(8, 0.02, 2.0);
}

void Arm:: shoulderDown(){
    transform(1, -0.05, 2.0);
}

void Arm:: reset(){
    transform(1, 0.5, 1.0);
    for(int i = 0; i < N_MOTOR;i++){
        transform(i, 0.01, 1.0);
    }
}
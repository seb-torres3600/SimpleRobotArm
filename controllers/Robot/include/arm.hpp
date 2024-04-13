#ifndef ARM_HPP
#define ARM_HPP

#include <vector>
#include <string>

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

#define N_MOTOR 9
#define PI 3.14

class Arm{
    private:
        webots::Robot *robot;
        std::vector<std::string> motor_names;
        std::vector<webots:: Motor*> motors;
        double time_step;
    public:
        Arm(webots::Robot *r);
        void travelMode();
        void transform(int motor_index, float target_location, float duration);
        void centerArm();
        void pickUpCan();
        void dropArm();
        void openClaws();
        void rotateHand();
        void shoulderDown();
        void reset();
        void closeClaws();
};


#endif
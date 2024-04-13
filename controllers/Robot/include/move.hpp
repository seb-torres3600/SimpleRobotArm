#ifndef MOVE_HPP
#define MOVE_HPP

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

#include <vector>
#include <string>

#define N_MOTORS 2
#define LEFT_WHEEL 0
#define RIGHT_WHEEL 1
#define MAX_SPEED 7.0

class Move{
    private:
        webots::Robot *robot;
        std::vector<std::string> motor_names;
        std::vector<webots::Motor*> motors;

    public:
        Move(webots::Robot *r);
        void forward();
        void slowDown();
        void stop();
        void backwards();
        void turn();
        void print_motor_names();
};

#endif
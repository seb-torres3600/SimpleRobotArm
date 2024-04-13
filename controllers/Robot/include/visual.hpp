#ifndef VISUAL_HPP
#define VISUAL_HPP

#include <webots/Camera.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include <vector>
#include <string>

#define H_MOTORS 2

class Visual{
    private:
        std:: vector<std::string> motor_names;
        std:: vector<webots::Motor*> motors;
        webots:: Robot *robot;
        webots:: Camera *camera_one;
        webots:: Camera *camera_two;
        double time_step;
        void transform(int motor_index, float target_location, float duration);
    public:
        Visual(webots::Robot *r);
        void panDown();
        void getRecognizedObjects();
};

#endif
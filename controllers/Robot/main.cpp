#include <iostream>
#include <vector>
#include <string>

#include <webots/Camera.hpp>
#include <webots/Motor.hpp>
#include <webots/RangeFinder.hpp>
#include <webots/Robot.hpp>
#include <webots/Keyboard.hpp>

#include "./include/move.hpp"
#include "./include/arm.hpp"
#include "./include/visual.hpp"

using namespace std;

vector<webots:: Motor> arm_motors;


int main(int argc, char **argv){
    vector<webots:: Motor*> wheel_motors;
    webots:: Robot *robot = new webots:: Robot();

    Move move(robot);
    Arm arm(robot);
    Visual visual(robot);

    visual.panDown();
    arm.reset();
    // visual.getRecognizedObjects();
    arm.pickUpCan();

    return 0;
}
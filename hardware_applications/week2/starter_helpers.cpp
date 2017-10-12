#include "starter_helpers.h"
using namespace std;

void run_robot(RJRobot &robot, const std::string &command){

 //"forward backward left right left forward waitForButton stop ";
    size_t index = commands.find(" ");
    size_t index_prev = 0;
    while(index != commands.length()){
        string sub_cmd = commands.substr(index_prev,index);
        execute_command(robot, sub_cmd);
        index_prev = index;
        index = commands.find(" ", index +1);
    }

}

//forward
void execute_command(RJRobot &robot, const std::string &command){
    if (command == "forward"){
        robot.SetMotor(MotorPort::A, 100);
        robot.SetMotor(MotorPort::B, 100);
        robot.Wait(250ms);
    } else if (command=="backward"){
        robot.SetMotor(MotorPort::A, -100);
        robot.SetMotor(MotorPort::B, 100);
        robot.Wait(250ms);
    }

}
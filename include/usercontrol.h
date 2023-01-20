#pragma once
#include "robot-config.h"
#include <math.h>
#include <cstdlib>

class userControl{
  public:
    void driveLoop();
    int flyspeed;
    int driveConst;
    bool flytog;
    userControl(robotChasis *robot, bool dM);
    
  private:
    robotChasis *robot1;
    void driveA();
    void driveB();
    void setBrakeMode();
    void turnUntil();
    
};


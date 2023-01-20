/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Cristian Robles                                           */
/*    Created:      Jan 19 2023                                               */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
 
using namespace vex;
robotChasis robot1 = robotChasis(2.75);// diameter of tracking 
odometry tracker = odometry(&robot1, 0);// robot, starting
autonomousControl autoChasis = autonomousControl(&robot1, &tracker);
autonomousRoutine autoRoutine = autonomousRoutine(&autoChasis);


int trackerWrapper(){
  tracker.updatePosition();
  return 0;
}

int printerWrapper(){
  tracker.updateScreen();
  return 0;
}

int autoWrapper(){
  autoChasis.autoMain();
  return 0;
}

task startTracking(trackerWrapper);
task startPrinting(printerWrapper);
task startAuto(autoWrapper);

void opControl(){                             
  startAuto.stop();
  userControl driveM = userControl(&robot1, true);
  driveM.driveLoop();
}

void autonM(){
  autoRoutine.run(1);
}

void disabledR(){
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit(&robot1);
  robot1.gyroM.resetHeading();
  robot1.Comp.drivercontrol(opControl);
  robot1.Comp.autonomous(autonM);
  while(1){
    if(!robot1.Comp.isEnabled()){
    disabledR();
    }
    wait(10, msec);
  }
}

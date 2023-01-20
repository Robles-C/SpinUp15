#include "usercontrol.h"
#include "visionUno.h"

userControl::userControl(robotChasis *robot, bool dM) {
  robot1 = robot;
  robot1->set_drive_break_type(coast);
}

void userControl::setBrakeMode() {
  if (robot1->Controller1.ButtonB.pressing())
    robot1->set_drive_break_type(hold);
  else if (robot1->Controller1.ButtonA.pressing())
    robot1->set_drive_break_type(coast);
}

void userControl::driveA(){
  robot1->LeftRear.spin(fwd,(robot1->Controller1.Axis3.value()+robot1->Controller1.Axis1.value()), velocityUnits::pct);
  robot1->LeftFront.spin(fwd,(robot1->Controller1.Axis3.value()+robot1->Controller1.Axis1.value()), velocityUnits::pct); 
  robot1->LeftMid.spin(fwd,(robot1->Controller1.Axis3.value()+robot1->Controller1.Axis1.value()), velocityUnits::pct);
  robot1->RightRear.spin(fwd,(robot1->Controller1.Axis3.value()-robot1->Controller1.Axis1.value()), velocityUnits::pct);
  robot1->RightFront.spin(fwd,(robot1->Controller1.Axis3.value()-robot1->Controller1.Axis1.value()), velocityUnits::pct);
  robot1->RightMid.spin(fwd,(robot1->Controller1.Axis3.value()-robot1->Controller1.Axis1.value()),velocityUnits::pct);
}

void userControl::driveB() {
  robot1->LeftRear.spin(fwd,.7*robot1->Controller1.Axis3.value(), velocityUnits::pct);
  robot1->LeftFront.spin(fwd,.7* (robot1->Controller1.Axis3.value()), velocityUnits::pct); 
  robot1->LeftMid.spin(fwd,.7* (robot1->Controller1.Axis3.value()), velocityUnits::pct);
  robot1->RightRear.spin(fwd,.7* robot1->Controller1.Axis2.value(), velocityUnits::pct);
  robot1->RightFront.spin(fwd, .7*(robot1->Controller1.Axis2.value()), velocityUnits::pct);
  robot1->RightMid.spin(fwd,.7* (robot1->Controller1.Axis2.value()),velocityUnits::pct);
}

void userControl::turnUntil() {
//leave blank I wanna try something here-cristian
}

void userControl::driveLoop() {
  flyspeed=100;
  flytog = false;
  while (true) {
    //setBrakeMode();
    driveB();
    if(robot1->Controller1.ButtonR2.pressing()){
      robot1->fly1.spin(fwd, flyspeed,velocityUnits::pct);
      robot1->fly2.spin(fwd, flyspeed,velocityUnits::pct);
    }else if(robot1->Controller1.ButtonX.pressing()){
      robot1->fly1.spin(fwd, 0,velocityUnits::pct);
      robot1->fly2.spin(fwd, 0,velocityUnits::pct);
    }
    //shift
    //if(flytog){
    //robot1->fly1.spin(fwd, flyspeed,velocityUnits::pct);
    //robot1->fly2.spin(fwd, flyspeed,velocityUnits::pct);
    //}else{
    //robot1->fly1.spin(fwd, 0,velocityUnits::pct);
    //robot1->fly2.spin(fwd, 0,velocityUnits::pct);
    //}
    //trans
    /*if(robot1->Controller1.ButtonR1.pressing()){
      robot1->LeftRear.spin(reverse,-5, velocityUnits::pct);
      robot1->LeftFront.spin(reverse, -5, velocityUnits::pct); 
      robot1->LeftMid.spin(reverse, -5, velocityUnits::pct);
      robot1->RightRear.spin(reverse, -5, velocityUnits::pct);
      robot1->RightFront.spin(reverse, -5, velocityUnits::pct);
      robot1->RightMid.spin(reverse, -5,velocityUnits::pct);
      robot1->intake1.spin(reverse,100,velocityUnits::pct);
      robot1->intake2.spin(reverse,100,velocityUnits::pct);
    }*/
    if(robot1->Controller1.ButtonL1.pressing()){
        robot1->intake1.spin(fwd, 100,velocityUnits::pct);
        robot1->intake2.spin(fwd, 100,velocityUnits::pct);
    }else if(robot1->Controller1.ButtonL2.pressing()){
        robot1->intake1.spin(fwd, -100,velocityUnits::pct);
        robot1->intake2.spin(fwd, -100,velocityUnits::pct);
    }else{
        robot1->intake1.spin(reverse, 0,velocityUnits::pct);
        robot1->intake2.spin(reverse, 0,velocityUnits::pct);
        robot1->intake1.setBrake(brake);
        robot1->intake2.setBrake(brake);
    }
    
    /*if(robot1->Controller1.ButtonB.pressing()){
      robot1->closeRange.open();
      robot1->midRange.close();
      flyspeed = 90;
    }else if(robot1->Controller1.ButtonDown.pressing()){
      robot1->midRange.open();
      robot1->closeRange.close();
      flyspeed = 90;
    }*/

    if(robot1->Controller1.ButtonR1.pressing()){
      robot1->loader.open();
      wait(750,msec);
      robot1->loader.close();
    }
    wait(20, msec);
  }
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      25 Jan 2022                                               */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#pragma once 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "tracking.h"
#include "usercontrol.h"
#include "chasisControl.h"
#include "autonomousRoutine.h"

#define TEST 0
#define ODOMETRYONLY 1
#define ODOMVISION 2

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*  This task is used to control your robot during the user control phase of  */
/*  a VEX Competition.                                                        */
/*                                                                            */
/*  You must modify the code to add your own robot specific commands here.    */
/*----------------------------------------------------------------------------*/

void usercontrol( void ) 
{
  // User control code here, inside the loop
    

  while (1)
  {
//arcade control, averages channels 3 and 4
        LeftDrive.spin(vex::directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, vex::velocityUnits::pct); //(Axis3+Axis4)/2
        RightDrive.spin(vex::directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, vex::velocityUnits::pct);//(Axis3-Axis4)/2
//lift control  
    LeftLift.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
    RightLift.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
//Claw Control
      Claw.spin(vex::directionType::fwd, Controller1.Axis1.value(), vex::velocityUnits::pct);
      
      
//Intake
if(Controller1.ButtonR2.pressing())
{
  
    Intake.spin(directionType::fwd, 100, velocityUnits::pct);
}
      if(Controller1.ButtonL2.pressing())
{
    Intake.spin(directionType::rev, 100, velocityUnits::pct);
}
//Flywheel
 if(Controller1.ButtonR1.pressing())
{
  
    Intake.spin(directionType::fwd, 100, velocityUnits::pct);
}     
      
      //vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}

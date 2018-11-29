v R#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Jumper1,        sensorDigitalIn)
#pragma config(Sensor, dgtl2,  Jumper2,        sensorDigitalIn)
#pragma config(Sensor, dgtl3,  Jumper3,        sensorDigitalIn)
#pragma config(Sensor, dgtl4,  Jumper4,        sensorDigitalIn)
#pragma config(Sensor, dgtl5,  Jumper5,        sensorDigitalIn)
#pragma config(Sensor, dgtl6,  Quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  mobileGoal,     sensorDigitalOut)
#pragma config(Sensor, dgtl9,  mobileGoal2,    sensorDigitalOut)
#pragma config(Motor,  port2,           leftside,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightside,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           fly,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Four,          tmotorVex393_MC29, openLoop)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int QuadReset;
int Quad1;
int mobile;
int four;
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
	QuadReset = 0;
	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

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

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  mobile=1;
four=1;
	while(1==1)
	{

		motor[rightside] = vexRT[Ch2];
		motor[leftside] = vexRT[Ch3];
		if(vexRT[Btn5U]==1)
		{
			motor(fly)=127;

		}
		else
		{
			motor(fly)=0;
		}

		if(vexRT[Btn5D]==1)
		{
			motor(fly)=-127;

		}
		else
		{
			motor(fly)=0;
		}

		if(vexRT[Btn6U]==1)
		{
			motor(arm)=127;
			motor(arm2)=127;
		}
		else
		{
			motor(arm)=0;
			motor(arm2)=0;
		}
		if(vexRT[Btn6D]==1)
		{
			motor(arm)=-127;
			motor(arm2)=-127;
		}
		else
		{
			motor(arm)=0;
			motor(arm2)=0;
		}

		//Rhea is my best friend :)
		//elephants are great & Dan is a butt
		//zezak I don't know how to code

		if(vexRT[Btn7D]==1)
		{
			if(mobile==1)
			{
				SensorValue[mobileGoal]=0;
				SensorValue[mobileGoal2]=0;
				mobile=0;
			}
			if(mobile==0)
			{
				SensorValue[mobileGoal]=1;
				SensorValue[mobileGoal2]=1;
				mobile=1;

			}
		}
		if(vexRT[Btn8D]==1)
		{
			if(four==1)
			{
				motor(Four)=127;
				untilPotentiometerGreaterThan(4000, potentiometer);
				four=0;
			}
			if(four==0)
			{
				motor(Four)=-127;
				untilPotentiometerLessThan(2000, potentiometer);
				four=0;

			}
		}

	}
}

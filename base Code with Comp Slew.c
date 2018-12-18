#pragma config(Sensor, in1,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Jumper1,        sensorDigitalIn)
#pragma config(Sensor, dgtl2,  Jumper2,        sensorDigitalIn)
#pragma config(Sensor, dgtl3,  Jumper3,        sensorDigitalIn)
#pragma config(Sensor, dgtl4,  Jumper4,        sensorDigitalIn)
#pragma config(Motor,  port2,           LeftDrivetrain, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RightDrivetrain, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           flywheel,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define MOTOR_NUM										kNumbOfTotalMotors
#define MOTOR_DEFAULT_SLEW_RATE			9
#define MOTOR_FAST_SLEW_RATE				256

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(3.0)
#pragma userControlDuration(9.0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
////////////////////////////////////////////////////////////////////////////////////////
int motorReq[ MOTOR_NUM ];
int motorSlew[ MOTOR_NUM ];
int Claw;
task slew()
{
	int speed;
	unsigned int motorIndex;

	for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++)//set up slew rates
	{

		motorReq[motorIndex]=0;
		if(MOTOR_NUM==5)
		{
			motorSlew[motorIndex]= MOTOR_DEFAULT_SLEW_RATE;
		}
		else if(MOTOR_NUM==7)
		{
			motorSlew[motorIndex]= MOTOR_DEFAULT_SLEW_RATE;
		}
		else
		{
			motorSlew[motorIndex]= MOTOR_FAST_SLEW_RATE;
		}

	}
	while(1==1)
	{
		for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++) //check for requests
		{
			speed=motor[motorIndex];
			if(speed != motorReq[motorIndex]) //check for diffrence
			{
				if(motorReq[motorIndex]> speed) // if motor speeding up
				{
					speed += motorSlew[motorIndex];
					if(speed > motorReq[motorIndex]) //end loop
					{
						speed = motorReq[motorIndex];
					}
				}
				if(motorReq[motorIndex] < speed) //if motor slowing down
				{
					speed -= motorSlew[motorIndex];
					if(speed < motorReq[motorIndex])
					{
						speed = motorReq[motorIndex];
					}
				}
			}
		}
	}

}
void pre_auton()
{

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	SensorValue[ClawPot]=0;
	Claw=1;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////


task autonomous()
{
	//top red
	if(SensorValue[Jumper1]==0)
	{
		motor[lift]=60;
		wait(.5);
		motor[lift]=0;
		wait(.1);
		motor(claw)=-47;
		wait(.25)
		motor(claw)=0;
		Claw=0;
		motor[lift]=-60;
		wait(.5);
		motor[lift]=0;
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
		wait(41/27.2);
		motor[LeftDrivetrain]=0;
		motor[RightDrivetrain]=0;
		motor[lift]=127;
		wait(.5);
		motor[lift]=0;
		motor(claw)=47;
		wait(.5)
		motor(claw)=0;
		Claw=1;
		motor[LeftDrivetrain]=63;
		motor[RightDrivetrain]=-63;
		wait(.5);
		motor[RightDrivetrain]=0;
		motor[LeftDrivetrain]=0;
		wait(1);
		motor[LeftDrivetrain]=63;
		motor[RightDrivetrain]=63;
		wait(17/ 27.2);
		motor[RightDrivetrain]=0;
		motor[LeftDrivetrain]=0;
		wait(1);
		motor[RightDrivetrain]=63;
		wait(.33);
		motor[lift]=-63;
		wait(.25);
		motor[RightDrivetrain]=-63;
		motor[LeftDrivetrain]=-63;
		motor(claw)=-47;
		wait(.5);
		motor(claw)=0;
		Claw=0;
	}
	if(SensorValue[Jumper2]==0)
	{
		//both bottom
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
		wait(.15);
		motor[LeftDrivetrain]=0;
		motor[RightDrivetrain]=0;
		motor[lift]=60;
		wait(.5);
		motor[lift]=0;
		wait(.1);


		motor(claw)=47;
		wait(.5);
		motor(claw)=0;
		Claw=0;
		wait(.5)
		motor[lift]=-60;
		wait(.5);
		motor[lift]=0;
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
		wait( 60/27.2	);
		motor[LeftDrivetrain]=0;
		motor[RightDrivetrain]=0;
		wait(1);
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
		wait(50/27.2);
		motor[LeftDrivetrain]=0;
		motor[RightDrivetrain]=0;
	}
	if (SensorValue[Jumper3]==0)
	{
		wait(4)
		motor[lift]=60;
		wait(.5);
		motor[lift]=0;
		wait(.1);


		motor(claw)=47;
		wait(.5);
		motor(claw)=0;
		Claw=0;
		wait(.5)
		motor[lift]=-60;
		wait(.5);
		motor[lift]=0;
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
		wait( 120/27.2	);
		motor[LeftDrivetrain]=0;
		motor[RightDrivetrain]=0;
	}
	if(sensorValue[Jumper4]==0)
	{
		motor(intake)=-127;
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
		wait(2.5)
		motor[LeftDrivetrain]=0;
		motor[RightDrivetrain]=0;
		motor(intake)=0;
	}
}

//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()

{
	startTask( slew );
	Claw=0;
	while(1==1)
	{

		motor[LeftDrivetrain] = vexRT[Ch3];
		motor[RightDrivetrain] = vexRT[Ch2];

		if(vexRT[Btn6D]==1)
		{
			motor(intake)=127;
		}
		else if(vexRT[Btn5D]==1)
		{
			motor(intake)=-127;

		}

		else
		{
			motor(intake)=0;
		}

		if(vexRT[Btn6U]==1)
		{
			motor(flywheel)=127;

		}
		else
		{
			motor(flywheel)=0;
		}

		if(vexRT[Btn5UXmtr2]==1)
		{
			motor(lift)=127;
		}
		else if(vexRT[Btn5DXmtr2]==1)
		{
			motor(lift)=-127;
		}
		else if(vexRT[Btn5UXmtr2]==0)
		{
			motor(lift)=0;
		}

		/*	if(vexRT[Btn8DXmtr2]==1)
		{
		if(Claw==0)
		{
		while(SensorValue[ClawPot]<368.5)//should be 180 degrees
		{
		motor(claw)=60;
		}
		motor(claw)=0;
		Claw=1;
		}
		if(Claw==1)
		{
		while(SensorValue[ClawPot]>-368.5)
		{
		motor(claw)=-60;
		}
		motor(claw)=0;
		Claw=0;
		}
		} */
		if(vexRT[Btn6UXmtr2]==1)
		{
			motor(claw)=37;
		}
		else if(vexRT[Btn6DXmtr2]==1)
		{
			motor(claw)=-37;
		}
		else if(vexRT[Btn6UXmtr2]==0)
		{
			motor(claw)=0;
		}
	}
}

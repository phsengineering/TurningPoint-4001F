#pragma config(Sensor, in1,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Jumper1,        sensorDigitalIn)
#pragma config(Sensor, dgtl2,  Jumper2,        sensorDigitalIn)
#pragma config(Sensor, dgtl3,  Jumper3,        sensorDigitalIn)
#pragma config(Sensor, dgtl4,  Jumper4,        sensorDigitalIn)
#pragma config(Sensor, dgtl5,  Jumper5,        sensorDigitalIn)
#pragma config(Sensor, dgtl6,  clawQuad,       sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  Auton,          sensorQuadEncoder)
#pragma config(Motor,  port2,           LeftDrivetrain, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RightDrivetrain, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           flywheel,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           flywheel2,     tmotorVex393_MC29, openLoop)
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

task Claws()
{
	if(vexRT[Btn8RXmtr2]==1)
	{
		SensorValue[ClawQuad]=0;
		{
			while(SensorValue[ClawQuad]<85)
			{
				motor(claw)=-15;
			}
			motor(claw)=0;
			SensorValue[ClawQuad]=0;
		}
	}
	if(vexRT[Btn8DXmtr2]==1)
	{

		{
			while(SensorValue[ClawQuad]<175)
			{
				motor(claw)=-30;
			}
			motor(claw)=0;
			SensorValue[ClawQuad]=0;
		}
	}
	if(vexRT[Btn5UXmtr2]==1)
	{
		motor(claw)=37;
	}
	else if(vexRT[Btn5DXmtr2]==1)
	{
		motor(claw)=-37;
	}
	else if(vexRT[Btn6UXmtr2]==0)
	{
		motor(claw)=0;
	}

}
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
	SensorValue[ClawQuad]=0;
	SensorValue[Auton]=0; //180 per rev
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

	if(SensorValue[Jumper1]==0)
		
{
	sensorValue[Auton]=0;
	while(SensorValue[Auton]>-1000) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-60;
		motor[RightDrivetrain]=-60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	motor(intake)=127;

	wait(.5);
	motor(intake)=0;

	while(SensorValue[Auton]<-850) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=60;
		motor[RightDrivetrain]=60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(1);
	while(SensorValue[Auton]>-980) ///////this is where the encoder isn425
	{
		motor[LeftDrivetrain]=-60;
		motor[RightDrivetrain]=60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5);
	while(SensorValue[Auton]>-1710) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5)

	motor(LeftDrivetrain)=40;
	motor(RightDrivetrain)=-40;

	wait(.32);
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=0;
	motor(intake)=-127;
	wait(.4);
	motor(intake)=0;


	motor(flywheel)=127;
	motor(flywheel2)=127;

	wait(3.5);

	motor(intake)=127;
	wait(.7);
	motor(intake)=0;
	motor(flywheel)=0;
	motor(flywheel2)=0;
	wait(.5);
	motor(flywheel)=127;
	motor(flywheel2)=127;
	wait(2);
	motor(intake)=127;
	wait(.7);
	motor(intake)=0;
	motor(flywheel)=0;
	motor(flywheel2)=0;
}
//}
if(SensorValue[Jumper2]==0)
{
	sensorValue[Auton]=0;
	while(SensorValue[Auton]>-1000) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor[LeftDrivetrain]=127;
	motor[RightDrivetrain]=127;
	wait(.1);
	motor[LeftDrivetrain]=0;
	motor[RightDrivetrain]=0;
	motor(intake)=127;
	wait(.5);
	motor(intake)=0;

	while(SensorValue[Auton]<330) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
	}
	motor[LeftDrivetrain]=-127;
	motor[RightDrivetrain]=-127;
	wait(.1);
	motor[LeftDrivetrain]=0;
	motor[RightDrivetrain]=0;
	wait(.5);
	while(SensorValue[Auton]<650) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=110;
		motor[RightDrivetrain]=-80;
	}
	motor[LeftDrivetrain]=-127;
	motor[RightDrivetrain]=127;
	wait(.1);
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	wait(.25);
	while(SensorValue[Auton]<950) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
	}
	motor[LeftDrivetrain]=-127;
	motor[RightDrivetrain]=-127;
	wait(.1);
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	wait(.5);
	motor(intake)=-127;
	wait(.2);
	motor(intake)=0;
	motor(flywheel)=127;
	motor(flywheel2)=127;

	wait(2.5);
	motor(intake)=127;
	wait(.4);
	motor(intake)=0;
	while(SensorValue[Auton]>0) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor[LeftDrivetrain]=127;
	motor[RightDrivetrain]=127;
	wait(.1);
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	wait(1)
	motor(intake)=127;
	wait(.75);
	motor(flywheel)=0;
	motor(flywheel2)=0;


	motor(intake)=0;
	while(SensorValue[Auton]>-670) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor[LeftDrivetrain]=127;
	motor[RightDrivetrain]=127;
	wait(.1);
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=-0;
	while(SensorValue[Auton]<1100) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
	}
	motor[LeftDrivetrain]=-127;
	motor[RightDrivetrain]=-127;
	wait(.1);
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=-0;
	wait(.5)
	while(SensorValue[Auton]>820) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=127;
	}
	motor[LeftDrivetrain]=127;
	motor[RightDrivetrain]=-127;
	wait(.1);
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	wait(.5)
	while(SensorValue[Auton]>-50) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
}

if (SensorValue[Jumper3]==0)//bottom red
{

	while(SensorValue[Auton]>-965) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}

	motor[LeftDrivetrain]=0;
	motor[RightDrivetrain]=0;
	motor(intake)=127;
	wait(.70);
	motor(intake)=0;

	while(SensorValue[Auton]<0) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
	}
	motor[LeftDrivetrain]=0;
	motor[RightDrivetrain]=0;
	wait(.5);
	while(SensorValue[Auton]>-220) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=127;
	}
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	wait(.25);
	while(SensorValue[Auton]<203) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
	}
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	motor(intake)=-127;
	wait(.175);
	motor(intake)=0;
	motor(flywheel)=127;
	motor(flywheel2)=127;

	wait(2.5);
	motor(intake)=127;
	wait(.4);
	motor(intake)=0;
	while(SensorValue[Auton]>-737) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor(RightDrivetrain)=0;
	motor(LeftDrivetrain)=0;
	wait(1)
	motor(intake)=127;
	wait(.75);
	motor(flywheel)=0;
	motor(flywheel2)=0;


	motor(intake)=0;
	while(SensorValue[Auton]>-1369) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}

	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5)
	while(SensorValue[Auton]<386) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=127;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5)
	while(SensorValue[Auton]<690) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=127;
		motor[RightDrivetrain]=-127;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5)
	while(SensorValue[Auton]>-50) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;

}
if(SensorValue[Jumper4]==0)//top
{
	sensorValue[Auton]=0;
	while(SensorValue[Auton]>-1000) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-60;
		motor[RightDrivetrain]=-60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	motor(intake)=127;

	wait(.5);
	motor(intake)=0;

	while(SensorValue[Auton]<-750) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=60;
		motor[RightDrivetrain]=60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(1);
	while(SensorValue[Auton]<-425) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=60;
		motor[RightDrivetrain]=-60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5);
	while(SensorValue[Auton]>-1100) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5)

	motor(LeftDrivetrain)=-40;
	motor(RightDrivetrain)=40;

	wait(.32);
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=0;
	motor(intake)=-127;
	wait(.4);
	motor(intake)=0;


	motor(flywheel)=127;
	motor(flywheel2)=127;

	wait(3.5);

	motor(intake)=127;
	wait(.7);
	motor(intake)=0;
	motor(flywheel)=0;
	motor(flywheel2)=0;
	wait(.5);
	motor(flywheel)=127;
	motor(flywheel2)=127;
	wait(2);
	motor(intake)=127;
	wait(.7);
	motor(intake)=0;
	motor(flywheel)=0;
	motor(flywheel2)=0;
}
	if(SensorValue[Jumper5]==0)
		
{
	sensorValue[Auton]=0;
	while(SensorValue[Auton]>-1000) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-60;
		motor[RightDrivetrain]=-60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	motor(intake)=127;

	wait(.5);
	motor(intake)=0;

	while(SensorValue[Auton]<-850) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=60;
		motor[RightDrivetrain]=60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(1);
	while(SensorValue[Auton]>-980) ///////this is where the encoder isn425
	{
		motor[LeftDrivetrain]=-60;
		motor[RightDrivetrain]=60;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5);
	while(SensorValue[Auton]>-1710) ///////this is where the encoder is
	{
		motor[LeftDrivetrain]=-127;
		motor[RightDrivetrain]=-127;
	}
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=-0;
	wait(.5)

	motor(LeftDrivetrain)=40;
	motor(RightDrivetrain)=-40;

	wait(.5);
	motor(LeftDrivetrain)=0;
	motor(RightDrivetrain)=0;
	wait(.5);
		motor(LeftDrivetrain)=127;
	motor(RightDrivetrain)=127;
	wait(2);

}
//}

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
	SensorValue[clawQuad]=0;

	while(1==1)
	{
		startTask( Claws );
		motor[LeftDrivetrain] = vexRT[Ch3];
		motor[RightDrivetrain] = vexRT[Ch2];

		if(vexRT[Btn6D]==1)
		{
			motor(intake)=127;
		}
		else if(vexRT[Btn5D]==1)
		{
			motor(intake)=-127;
			//	motor(flywheel)=-127;
			//	motor(flywheel2)=-127;
		}

		else if(vexRT[Btn6U]==1)
		{
			motor(flywheel)=127;
			motor(flywheel2)=127;
		}
		else
		{
			motor(intake)=0;
			motor(flywheel)=0;
			motor(flywheel2)=0;
		}


		if(vexRT[Btn6UXmtr2]==1)
		{
			motor(lift)=63;
		}
		else if(vexRT[Btn6DXmtr2]==1)
		{
			motor(lift)=-63;
		}
		else if(vexRT[Btn6UXmtr2]==0)
		{
			motor(lift)=0;
		}


	}
}
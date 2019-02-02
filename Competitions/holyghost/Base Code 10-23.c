4#pragma config(Sensor, in1,    ClawPot,        sensorPotentiometer)
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

int Claw;
int motorReq[ MOTOR_NUM ];
int motorSlew[ MOTOR_NUM ];

task slew()
{
	int speed;
	unsigned int motorIndex;

	for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++)//set up slew rates
	{

	motorReq[motorIndex]=0;
		if(MOTOR_NUM==6)
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
task main()
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

		if(vexRT[Btn5U]==1)
		{
			motor(lift)=127;
		}
		else if(vexRT[Btn5D]==1)
		{
			motor(lift)=-127;
		}
		else if(vexRT[Btn5U]==0)
		{
			motor(lift)=0;
		}

		if(vexRT[Btn8D]==1)
		{
			if(Claw==0)
			{
				while(SensorValue[ClawPot]<737)//should be 180 degrees
				{
					motor(claw)=60;
				}
				motor(claw)=0;
				Claw=1;
			}
			if(Claw==1)
			{
				while(SensorValue[ClawPot]>0)
				{
					motor(claw)=-60;
				}
				motor(claw)=0;
				Claw=0;
			}
		}
	}
}

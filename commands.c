#pragma config(StandardModel, "RVW CLAWBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//Robot number 3
#define DRIVE_TRAIN_SPEED 50
#define DRIVE_TRAIN_ANGLE 90

#define ARM_SPEED 20
#define CLAW_SPEED 40

const float SPEED_TO_CM_SEC = -1;
//const float DEGREE_TO_CM

static int driveTrainSpeed = 0;
static int driveTrainAngle = 0;

static int armSpeed = 0;
static int armPosition = 0;

static int clawSpeed = 0;
static int clawPosition = 0;

// Drive train
void setDriveTrainSpeed(int speed)
{
	driveTrainSpeed = speed;
}

void setDriveTrainAngle(int angle)
{
	driveTrainAngle = angle;
}

void moveDriveTrain()
{
	motor[leftMotor] = driveTrainSpeed;
	motor[rightMotor] = driveTrainSpeed;
}

void stopDriveTrain()
{
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

// Arm
void setArmSpeed(int speed)
{
	armSpeed = speed;
}

void setArmPosition(int degrees)
{
	armPosition = degrees;
}

void stopArm()
{
	motor[armMotor] = 0;
}

// Claw
void setClawSpeed(int speed)
{
	clawSpeed = speed;
}

void setClawPosition(int degrees)
{
	clawPosition = degrees;
}

void stopClaw()
{
	motor[clawMotor] = 0;
}

void initializeSystem()
{
	setDriveTrainSpeed(DRIVE_TRAIN_SPEED);
	setDriveTrainAngle(DRIVE_TRAIN_ANGLE); // robot points north
	stopDriveTrain();

	setArmSpeed(ARM_SPEED);
	setArmPosition(0);
	stopArm();

	setClawSpeed(CLAW_SPEED);
	setClawPosition(0);
	stopClaw();
}

void resetSystem()
{
	stopDriveTrain();
	setDriveTrainAngle(0);
	setDriveTrainSpeed(0);

	stopArm();
	setArmSpeed(0);

	stopClaw();
	setClawSpeed(0);
}

void moveDistance(float distance)
{
	float cmPerSec = driveTrainSpeed / SPEED_TO_CM_SEC;
	float time = distance / cmPerSec;

	moveDriveTrain();
	wait1Msec(time);
	stopDriveTrain();
}

void turn(int degrees)
{

}

task main()
{
	initializeSystem();
	setDriveTrainSpeed(10);

	/*motor[leftMotor] = driveTrainSpeed;
	motor[rightMotor] = driveTrainSpeed;
	wait1Msec(300);*/

	resetSystem();
}

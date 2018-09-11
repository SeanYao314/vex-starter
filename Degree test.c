#pragma config(Motor,  port1,           topRight,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           bottomLeft,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          bottomRight,   tmotorVex393_HBridge, openLoop)

int TURN_SPEED = 50;


void move(int leftSpeed, int rightSpeed) {
	motor(topRight) = rightSpeed;
	motor(bottomRight) = rightSpeed;
	motor(topLeft) = leftSpeed;
	motor(bottomLeft) = leftSpeed;
}

void stop () {
	move(0,0);
}

void turn_left(int degree) {
	float time = (degree/TURN_SPEED)*1000;
	move(-TURN_SPEED, TURN_SPEED);
	wait1Msec(time);
	stop();
}

void turn_right(int degree) {
	float time = (degree/TURN_SPEED)*1000;
	move(TURN_SPEED, -TURN_SPEED);
	wait1Msec(time);
	stop();
}

void forward(int distance) {
	float time = (distance/TURN_SPEED)*1000;
	move(TURN_SPEED, TURN_SPEED);
	wait1Msec(time);
	stop();
}

void backwards(int distance) {
	float time = (distance/TURN_SPEED)*1000;
	move(-TURN_SPEED, -TURN_SPEED);
	wait1Msec(time);
	stop();
}

task main()
{

}

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

void foward(int distance) {
	float time = (distance/TURN_SPEED)*1000;
	move(TURN_SPEED, TURN_SPEED);
	wait1Msec(time);
	stop();
}

void backwards(int distance) {
	float time = (distance/TURN_SPEED)*1000;
	move(TURN_SPEED, -TURN_SPEED);
	wait1Msec(time);
	stop();
}

task main()
{
	//initial movement
	forward(50);
	turn_left(90);
	forward(60);
	turn_right(90);
	forward(50);

	//move back to the original position

	// foward(10);
	// backwards(10);
	// turn_left(90);
	// foward(10);
	// turn_right(90);
	// backwards(90);
	// turn_left(50);
	// turn_right(50);
}

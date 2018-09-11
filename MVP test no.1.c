#pragma config(Motor,  port1,           TopRight,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           TopLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          BottomRight,   tmotorVex393_HBridge, openLoop, reversed)

int x = 500000;
int speed = 50;
int distance = x;
int neg_speed = -50;
float time = distance/speed;

void forwards(int speed, float time) {
	motor(TopLeft) = speed;
	motor(TopRight) = speed;
	motor(BottomRight) = speed;
	motor(BottomLeft) = speed;
	wait1Msec(time);
}
void backwards(int neg_speed, float time) {
	motor(TopLeft) = neg_speed;
	motor(TopRight) = neg_speed;
	motor(BottomRight) = neg_speed;
	motor(BottomLeft) = neg_speed;
	wait1Msec(time);
}
void turn_left(int speed, int neg_speed, float time) {
	motor(TopLeft) = neg_speed;
	motor(TopRight) = speed;
	motor(BottomRight) = speed;
	motor(BottomLeft) = neg_speed;
	wait1Msec(time);
}
void turn_right(int speed, int neg_speed, float time) {
	motor(TopLeft) = speed;
	motor(TopRight) = neg_speed;
	motor(BottomRight) = neg_speed;
	motor(BottomLeft) = speed;
	wait1Msec(time);
	}

task main()
{
/*


*/
}

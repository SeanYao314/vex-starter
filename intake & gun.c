#pragma config(Motor,  port1,           intake,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           gun,           tmotorVex393_MC29, openLoop)

int intakeSpeed = -50;
int gunSpeed = 75;
task main(){
	while (true) {
		if (vexRT[Btn5U] == 1) {
			motor(intake) = intakeSpeed;
		} else {
			motor(intake) = 0;
		}
		if (vexRT[Btn5D] == 1) {
			motor(intake) = 50;
		} else {
			motor(intake) = 0;
		}
		if (vexRT[Btn6U] == 1) {
			motor(gun)  = gunSpeed;
		} else {
			motor(gun) = 0;
		}
	}
}

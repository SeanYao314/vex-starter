#pragma config(Motor,  port1,           Intake,        tmotorVex393_HBridge, openLoop)

int intakeSpeed = -50;

task intake_control() {
	while (true) {
		if (VexBtn(5U) == 1) {
			Motor(Intake) == intakeSpeed;
		} else {
			intakeSpeed = 0;
		}
		if (VexBtn(5D) == 1) {
			Motor(Intake) == -intakeSpeed;
		} else {
			intakeSpeed = 0;
		}
	}
}

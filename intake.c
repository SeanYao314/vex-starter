
int _intake_motor_speed = -50;

task intake_control() {
	while (true) {
		if (vexRT(Btn5U) == 1) {
			Motor(Intake) == _intake_motor_speed;
		} else if (vexRT(Btn5D) == 1) {
			Motor(Intake) == -_intake_motor_speed;
		} else {
			Motor(Intake) == 0;
		}
	}
}

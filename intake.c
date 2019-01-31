int _intake_motor_speed = 120;

task intake_control() {
	while (true) {
		if (vexRT(Btn5U) == 1 || vexRT(Btn5UXmtr2) == 1) {
			motor(Intake) = _intake_motor_speed;
		} else if (vexRT(Btn5D) == 1 || vexRT(Btn5DXmtr2) == 1) {
			motor(Intake) = -1 * _intake_motor_speed;
		} else {
			motor(Intake) = 0;
		}
		wait1Msec(100);
	}
}

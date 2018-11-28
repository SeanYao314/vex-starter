
int _gun_motor_speed = -127;

bool is_gun_triggered() {
	return vexRT(Btn6U) == 1 || vexRT(Btn6UXmtr2) == 1;
}

task gun_control() {
	while (true) {
		if (is_gun_triggered()) {
			motor(Gun) = _gun_motor_speed;
		} else {
			motor(Gun) = 0;
		}
		wait1Msec(100);
	}
}

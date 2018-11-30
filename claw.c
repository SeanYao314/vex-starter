int _claw_motor_threshold = 20;

void _move_claw(int speed) {
	motor(Claw) = speed;
}

void _stop_claw() {
	_move_claw(0);
}

int _get_claw_speed() {
	int claw_speed = 0;
	if (vexRT(Btn6UXmtr2) == 1 || vexRT(Btn6U) == 1 ) {
		claw_speed = 80;
	} else if (vexRT(Btn6DXmtr2) == 1 || vexRT(Btn6D) == 1 ) {
		claw_speed = -80;
	}
	return claw_speed;
}

bool _should_move_claw() {
	return abs(_get_claw_speed()) > _claw_motor_threshold;
}

task claw_control() {
	while (true) {
		if(_should_move_claw()) {
			_move_claw(_get_claw_speed());
		} else {
			_stop_claw();
		}
		wait1Msec(100);
	}
}

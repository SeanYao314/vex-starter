int _claw_motor_threshold = 20;

void _move_claw(int speed) {
	motor(Claw) = speed;
}

void _stop_claw() {
	_move_claw(0);
}

int _get_claw_speed() {
	int claw_speed = 0;
	// if (vexRT(Ch3Xmtr2) > 20 || vexRT(Btn6U) == 1 ) {
	// 	claw_speed = vexRT(Ch3Xmtr2) * abs(vexRT(Btn6U) - 1) + vexRT(Btn6U) * 80;
	// } else if (vexRT(Ch3Xmtr2) < -20 || vexRT(Btn6D) == 1 ) {
	// 	claw_speed = -(vexRT(Ch3Xmtr2) * abs(vexRT(Btn6D - 1)) + vexRT(Btn6D) * 80);
	// }
	if (abs(vexRT(Ch3Xmtr2)) > _claw_motor_threshold) {
		claw_speed = vexRT(Ch3Xmtr2);
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

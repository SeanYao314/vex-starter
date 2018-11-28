int _claw_motor_threshold = 20;

void _move_claw(int speed) {
	motor(Claw) = speed;
}

void _stop_claw() {
	_move_claw(0);
}

int _get_claw_speed() {
	if (abs(vexRT(Ch3Xmtr2)) > abs(vexRT(Ch4))) {
		return vexRT(Ch3Xmtr2);
	} else {
		return vexRT(Ch4);
	} 
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

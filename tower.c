int _tower_motor_threshold = 50;

void _move_tower(int speed) {
	motor(Tower1) = speed;
	motor(Tower2) = speed;
}

void _stop_tower() {
	_move_tower(0);
}

int _get_tower_speed() {
	return vexRT(Ch3);
}

bool _should_move_tower() {
	return abs(_get_tower_speed()) > _tower_motor_threshold;
}

task tower_control() {
	while (true) {
		if(_should_move_tower()) {
			_move_tower(_get_tower_speed() * 127);
		} else {
			_stop_tower();
		}
		wait1Msec(100);
	}
}

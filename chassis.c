int CHASSIS_MOTOR_THRESHOLD = 15;


void drive_chassis(int left_speed, int right_speed) {
	Motor(LeftFront) = left_speed;
	Motor(LeftRear)  = left_speed;
	Motor(RightFront) = right_speed;
	Motor(RightRear) = right_speed;
}

void stop_chassis() {
	drive_chassis(0, 0);
}

void rotate_chassis(int rotate_speed) {
	drive_chassis(rotate_speed, -1 * rotate_speed);
}

task chassis_control() {
	while (true) {
		int drive_speed = vexRT[Ch2];
		int turn_speed = vexRT[Ch1];
		int rotate_speed = vexRT[Ch4];

		if (abs(rotate_speed) > CHASSIS_MOTOR_THRESHOLD) {
			rotate_chassis(rotate_speed);
		} else if (abs(drive_speed) > CHASSIS_MOTOR_THRESHOLD) {
			int left_speed = drive_speed;
			int right_speed = drive_speed;
			if (abs(turn_speed) > CHASSIS_MOTOR_THRESHOLD) {
				if (turn_speed < 0) {
					left_speed -= turn_speed;
				} else {
					right_speed += turn_speed;
				}
			}
			drive_chassis(left_speed, right_speed);
		} else {
			stop_chassis();
		}
	}
}

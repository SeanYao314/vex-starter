int CHASSIS_MOTOR_THRESHOLD = 20;


void drive_chassis(int left_speed, int right_speed) {
	motor(LeftFront) = left_speed;
	motor(LeftRear)  = left_speed;
	motor(RightFront) = right_speed;
	motor(RightRear) = right_speed;
}

void stop_chassis() {
	drive_chassis(0, 0);
}

task chassis_control() {
	while (true) {
		int left_speed = vexRT[Ch2] + vexRT[Ch1];
		int right_speed = vexRT[Ch2] - vexRT[Ch1];

		int max_input = max(abs(left_speed), abs(right_speed));
		if (max_input >= CHASSIS_MOTOR_THRESHOLD) {
			drive_chassis(left_speed, right_speed);
		} else {
			stop_chassis();
		}
		wait1Msec(100);
	}
}

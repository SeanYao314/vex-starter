
int _gun_motor_speed = 75;

task gun_control() {
	while (true) {
		if(VexRt(Btn6U) == 1) {
			Motor(Gun) = _gun_motor_speed;
		} else {
			Motor(Gun) = 0;
		}
	}
}

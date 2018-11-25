
int _gun_motor_speed = 75;

task gun_control() {
	while (true) {
		if(vexRT(Btn6U) == 1) {
			motor(Gun) = _gun_motor_speed;
		} else {
			motor(Gun) = 0;
		}
		wait1Msec(100);		
	}
}

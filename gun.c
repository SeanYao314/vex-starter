#pragma config(Motor,  port6,           Gun,           tmotorVex393_MC29, openLoop)

int gunSpeed = 75;

task gun_control() {
	while (true) {
		if(VexBtn(6U) == 1) {
			Motor(Gun) = gunSpeed;
		} else {
			Motor(Gun) = 0;
		}
	}
}

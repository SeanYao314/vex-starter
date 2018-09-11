#pragma config(Motor,  port2,           UpLeft,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           UpRight,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           DownLeft,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           DownRight,           tmotorVex393_MC29, openLoop)

int threshold = 10;
task chassis_control(){
	while (true) {
		if(abs(VexRT(Ch2)) > threshold) {
			Motor(UpLeft) = VexRt(Ch2);
			Motor(UpRight) = VexRt(Ch2);
			Motor(DownLeft) = VexRt(Ch2);
			Motor(DownRight) = VexRt(Ch2);
		} else {
			Motor(UpLeft) = 0;
			Motor(UpRight) = 0;
			Motor(DownLeft) = 0;
			Motor(DownRight) = 0;
		}
		if(abs(VexRT(Ch4)) > threshold) {
			Motor(UpLeft) = VexRT(Ch4);
			Motor(UpRight) = -VexRt(Ch4);
			Motor(DownRight) = -VexRT(Ch4);
			Motor(DownLeft) = VexRT(Ch4);
		} else {			
			Motor(UpLeft) = 0;
			Motor(UpRight) = 0;
			Motor(DownLeft) = 0;
			Motor(DownRight) = 0;
		}
	}
}
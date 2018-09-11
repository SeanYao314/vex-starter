#pragma config(Motor,  port6,           TowerUpLeft,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port7,           TowerUpRight,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port8,           TowerDownLeft,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port9,           TowerDownRight,         tmotorVex393_HBridge, openLoop)

int threshold = 10;
int armspeed = 100; 
task tower_control()
{
	while (true) {
		if(abs(VexRT(Ch3)) > threshold) {
			Motor(TowerUpLeft) = armspeed;
			Motor(TowerDownRight) = armspeed;
			Motor(TowerDownLeft) = armspeed;
			Motor(TowerUpRight) = armspeed; 
		} else {
			Motor(TowerUpLeft) = 0;
			Motor(TowerDownRight) = 0;
			Motor(TowerDownLeft) = 0;
			Motor(TowerUpRight) = 0; 
		}
	}
}

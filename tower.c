#pragma config(Motor,  port1,           tower,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true) {
		motor[tower] = vexRT[Ch2];
	}
}

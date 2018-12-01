void auton3() {
	chassisForward(50);
	wait1Msec(750);
	turn(90);
	stopChassis();

	chassisForward(127);
	wait1Msec(2250);
	stopChassis();
}
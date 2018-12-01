void auton3() {
	chassisBackwards(50);
	wait1Msec(1500);
	turn(90);
	stopChassis();

	chassisForward(90);
	wait1Msec(800);
	stopChassis();

	wait1Msec(800);
	chassisBackwards(127);
	wait1Msec(4000);
	stopChassis();
}
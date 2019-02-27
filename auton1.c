void auton1() {
	forward(1, 1);
	pause();
	shoot();
	wait1Msec(2500);
	stopGun();
	pause();

	GyroTurnClockwise(90);

	forwardEncoder(11.8, 127);
	pause();

	GyroTurnClockwise(90);
	pause();

	chassisBackwards(127);
	wait1Msec(900);
	stopChassis();
	pause();

	chassisForward(127);
	wait1Msec(3000);
	stopChassis();
}

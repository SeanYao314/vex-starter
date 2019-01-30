void onebuttonauton() {
	shoot();
	wait1Msec(2500);
	stopGun();

	GyroTurnCounterClockwise(90);
	pause();

	forwardEncoder(25, 127);
	pause();

	backwardEncoder(5, 100);
	GyroTurnClockwise(135)
	pause();

	backwardEncoder(6, 127);
	pause();

	clawDown();
	wait1Msec(2000);
	stopclaw();

}
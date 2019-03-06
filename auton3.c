void auton3() {
	chassisForward(127);
	wait1Msec(2500);
	stopChassis();
	pause();

	backwardEncoderAdaptiveSpeed(11, 127, false);
	shoot();
	backwardEncoder(12, 127);
	pause();

	gyroTurnClockwise(90);
	wait1Msec(1500);
	stopGun();

	backwardEncoder(15, 127);
	pause();

	forwardEncoder(7, 127);
	stopall(200);
}

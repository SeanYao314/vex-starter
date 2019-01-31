void onebuttonauton() {
	shoot();
	wait1Msec(2500);
	stopGun();
	pause();

	backwardEncoder(1, 127);
	pause();
	GyroTurnCounterClockwise(90);
	pause();

	intakeIn();
	chassisForward(127);
	wait1Msec(2500);
	stopall(200);

	backwardEncoderAdaptiveSpeed(5, 100, false);
	pause();

	clawDown();
	GyroTurnCounterClockwise(57);
	stopall(200);

	// backwardEncoder(4, 127);
	// pause();

	// clawUp();
	// wait1Msec(1000);
	// stopclaw();

	// backwardEncoder(22, 127);
	// pause();

	// GyroTurnClockwise(90);
	// pause();

	// forwardEncoder(22, 127);
	// pause();

	// clawUp();
	// wait1Msec(1000);
	// stopclaw();
	// pause();

	// intakeIn();
	// forwardEncoder(3, 127);
	// stopall(200);
}
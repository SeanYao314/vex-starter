void autonSkills2() {
	forwardEncoder(1, 1);
	pause();
	//shoot
	shoot();
	wait1Msec(2900);

	intakeFlip();
	forwardEncoderAdaptiveSpeed(13, 127, false)
	pause();
	stopGun();
	forwardEncoder(3, 127);
	stopIntake();
	pause()
	intakeIn();
	forwardEncoder(2.5, 127);

	wait1Msec(3600);
	pause();
	stopIntake();

	//gyroTurnClockwise(5);
	//pause();
	shoot();
	wait1Msec(2750);
	pause()
	stopGun();

	//gyroTurnCounterClockwise(5);
	//pause();

	chassisBackwards(127);
	wait1Msec(3500);
	stopChassis();

	forwardEncoder(3, 50);
	pause()

	gyroTurnClockwise(90);
	pause();

	forwardEncoder(10.2, 127);
	pause();

	gyroTurnCounterClockwise(90);
	pause();

	chassisBackwards(127);
	wait1Msec(750);
	stopChassis();
	pause();

	intakeIn();
	chassisForward(127);
	wait1Msec(4700);

	chassisBackwards(50);
	wait1Msec(250);
	stopall(20);
}

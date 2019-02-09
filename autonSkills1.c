void autonSkills1() {
	forwardEncoder(1, 1)
	//shoot
	shoot();
	wait1Msec(2100);
	stopGun();
	pause();

	backwardEncoder(1.75, 127);
	pause();

	gyroTurnCounterClockwise(90);
	pause();

	//push flag
	intakeIn();
	chassisForward(127);
	wait1Msec(2500);
	stopall(100);

	//pause();
	pause();

	backwardEncoderAdaptiveSpeed(5, 35, true);
	pause();

	gyroTurnClockwise(90);
	pause();

	//bang the wall
	chassisBackwards(100);
	wait1Msec(500);
	stopall(100);

	pause();

	//move to middle flag pole
	forwardEncoder(22, 127);

	pause();

	gyroTurnCounterClockwise(92);
	pause();

	chassisForward(100);
	wait1Msec(1000);
	stopall(100);

	pause();

	backwardEncoderAdaptiveSpeed(6, 127, true);
	pause();

	gyroTurnClockwise(90);
	pause();

	//move to last flag pole
	forwardEncoder(20, 127);
	pause();

	gyroTurnCounterClockwise(92);
	pause();

	// clawDown();
	pause();
	chassisForward(100);
	wait1Msec(1000)
	stopall(100);

	pause();

	backwardEncoderAdaptiveSpeed(5, 127, true);
	// clawUp();
	pause();

	gyroTurnClockwise(90);
	pause();

	//bang the wall
	chassisForward(127);
	wait1Msec(1500);
	stopall(100);

	pause();

	backwardEncoderAdaptiveSpeed(2, 50, false);
	pause();

	gyroTurnClockwise(90);
	pause();

	chassisForward(127);
	wait1Msec(5500);
	stopall(100);
	pause();

	backwardEncoder(22, 127);

	gyroTurnClockwise(90);
	pause();

	//bang the wall
	chassisBackwards(100);
	wait1Msec(700);
	stopall(100);

	pause();

	intakeIn();
	chassisForward(127);
	wait1Msec(4600);
	pause();
	chassisBackwards(50);
	pause();
	stopall(500);
}
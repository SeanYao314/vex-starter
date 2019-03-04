void autonSkills1() {
	forwardEncoder(1, 1)
	//shoot
	shoot();
	wait1Msec(2750);
	stopGun();
	pause();


	intakeIn();
	forwardEncoder(17, 127);
	wait1Msec(3100);
	pause();
	stopIntake();
	intakeFlip();
	forwardEncoder(5, 127);
	stopIntake();
	backwardEncoder(1.95, 127);
	pause();

	// intakeFlip();
	// forwardEncoder(16, 127);
	// wait1Msec(300);
	// stopIntake();
	// intakeIn();
	// wait1Msec(2400);
	// forwardEncoder(4, 127);
	// stopall(10);

	shoot();
	wait1Msec(3500);
	stopGun();
	backwardEncoder(2.06, 127);

	//move to middle flag pole
	pause();

	gyroTurnCounterClockwise(90);
	pause();

	intakeIn();
	chassisForward(100);
	wait1Msec(2300);
	stopall(100);

	pause();

	backwardEncoderAdaptiveSpeed(5.2, 127, true);
	pause();

	gyroTurnClockwise(90);
	pause();

	//move to last flag pole
	forwardEncoder(20.6, 127);
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

	/* vvvvvvvvvvvvv this section move the chassis all the way to the wall, then com back vvvvvvv **/
	chassisForward(127);
	intakeIn();
	wait1Msec(5000);
	
	stopall(100);
	pause();

	backwardEncoder(21.55, 127);

	gyroTurnClockwise(90);
	pause();
	/*^^^^^^^^^ this section move the chassis all the way to the wall, then com back ^^^^^^^^^ **/

	//bang the wall
	chassisBackwards(100);
	wait1Msec(700);
	stopall(100);

	pause();

	intakeIn();
	chassisForward(127);
	wait1Msec(4630);
	pause();
	chassisBackwards(50);
	wait1Msec(100);
	stopall(10);
}
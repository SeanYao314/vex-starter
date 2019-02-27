void autonSkills2() {
	forwardEncoder(1, 1);
	pause();
	//shoot
	shoot();
	wait1Msec(2000);
	stopGun();

	gyroTurnCounterClockwise(90);
	pause();

	//push flag
	// intakeIn();
	// forwardEncoder(21, 127);
	// stopall(100);

	// pause();
	pause();

	backwardEncoder(11, 127);
	pause();

	gyroTurnClockwise(90);
	pause();

	chassisBackwards(100);
	wait1Msec(500);

	intakeIn();
	chassisForward(127);
	wait1Msec(4700);
	chassisBackwards(50);
	pause();
	stopall(2);
}


// void autonSkills2() {
// 	shoot();
// 	wait1msec(3000);
// 	stopGun();

// 	turn(90);

// 	chassisBackwards(50);
// 	wait1Msec(1500);
// 	turnCounterClock(90);
// 	stopChassis();

// 	chassisForward(90);
// 	wait1Msec(800);
// 	stopChassis();

// 	wait1Msec(800);
// 	chassisBackwards(127);
// 	intakeIn();
// 	wait1Msec(4500);
// 	stopall(500);
// }
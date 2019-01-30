void onebuttonauton() {
	shoot();
	wait1Msec(5000);
	stopGun();

	turnCounterClock(90);

	chassisBackwards(100);
	wait1Msec(3000);
	stopChassis();

	chassisForward(75);
	wait1Msec(1000);
	stopChassis();

	turnCounterClock(45);
	clawUp();
	wait1Msec(2000);
	stopClaw();

	chassisForward(50);
	clawDown();
	wait1Msec(1000);
	stopClaw();
}
void auton1() {
	clawDown();
	shoot();
	wait1Msec(1000);
	stopClaw();
	wait1Msec(500);
	stopGun();

	turn(45);

	chassisForward(80);
	wait1Msec(1000);
	stopChassis();

	clawUp();
	wait1Msec(1000);
	clawStop();

	chassisForward(80)
	wait1Msec(1000);
	turn(45);
	stopChassis();

	chassisBackwards(127);
	wait1Msec(4000);
	stopChassis();
}

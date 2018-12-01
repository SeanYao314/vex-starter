void stopChassis(int time) {
	motor(leftRear) = 0;
	motor(rightRear) = 0;
	motor(leftFront) = 0;
	motor(rightFront) = 0;
	wait1Msec(time);
}
void stopTower() {
	motor(towerUp) = 0;
	motor(towerDown) = 0;
}
void stopIntake() {
	motor(Intake) = 0;
}
void stopClaw() {
	motor(Claw) = 0;
}
void stopGun() {
	motor(Gun) = 0;
}
void stopall(int time) {
	motor(leftRear) = 0;
	motor(rightRear) = 0;
	motor(leftFront) = 0;
	motor(rightFront) = 0;
	motor(towerUp) = 0;
	motor(towerDown) = 0;
	motor(Intake) = 0;
	motor(Claw) = 0;
	motor(Gun) = 0;
	wait1Msec(time);
}
void chassisForward(int speed) {
	motor(leftRear) = speed;
	motor(rightRear) = speed;
	motor(leftFront) = speed;
	motor(rightFront) = speed;
}
void chassisBackward(int time, int speed) {
	motor(leftRear) = -speed;
	motor(rightRear) = -speed;
	motor(leftFront) = -speed;
	motor(rightFront) = -speed;
	wait1Msec(time);
}
void chassisRight(int time, int speed) {
	motor(leftRear) = speed;
	motor(rightRear) = -speed;
	motor(leftFront) = speed;
	motor(rightFront) = -speed;
	wait1Msec(time);
}
void chassisLeft(int time, int speed) {
	motor(leftRear) = -speed;
	motor(rightRear) = speed;
	motor(leftFront) = -speed;
	motor(rightFront) = speed;
	wait1Msec(time);
}
void TowerUp(int time, int speed) {
	motor(towerUp) = speed;
	motor(towerDown) = speed;
	wait1Msec(time);
}
void TowerDown(int time, int speed) {
	motor(towerUp) = -speed;
	motor(towerDown) = -speed;
	wait1Msec(time);
}
void clawUp() {
	motor(Claw) = 80;
}
void clawDown() {
	motor(Claw) = -80;
}
void intakeIn(int time) {
	motor(Intake) = 120;
	wait1Msec(time);
}
void intakeFlip(int time) {
	motor(Intake) = -120;
	wait1Msec(time);
}
void shoot(int time) {
	motor(Gun) = -127;
	wait1Msec(time);
}
void turn(int degrees) {
	int speed = 50;
	int fullRotationTime = 2000;
	int time = fullRotationTime/360*degrees;
	motor(leftRear) = speed;
	motor(rightRear) = -speed;
	motor(leftFront) = speed;
	motor(rightFront) = -speed;
	wait1Msec(time);
	stopChassis(0);
}
void turnCounterClock(int degrees) {
	int speed = 50;
	int fullRotationTime = 2000;
	int time = fullRotationTime/360*degrees;
	motor(leftRear) = -speed;
	motor(rightRear) = speed;
	motor(leftFront) = -speed;
	motor(rightFront) = speed;
	wait1Msec(time);
	stopChassis(0);
}
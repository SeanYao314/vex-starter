void stopChassis() {
	motor(LeftRear) = 0;
	motor(RightRear) = 0;
	motor(LeftFront) = 0;
	motor(RightFront) = 0;
	wait1Msec(100);
}
// void stopTower() {
// 	motor(towerUp) = 0;
// 	motor(towerDown) = 0;
// }
// void stopIntake() {
// 	motor(Intake) = 0;
// }
void stopClaw() {
	motor(Claw) = 0;
}
void stopGun() {
	motor(Gun) = 0;
}
void stopall(int time) {
	motor(LeftRear) = 0;
	motor(RightRear) = 0;
	motor(LeftFront) = 0;
	motor(RightFront) = 0;
	motor(towerUp) = 0;
	motor(towerDown) = 0;
	motor(Intake) = 0;
	motor(Claw) = 0;
	motor(Gun) = 0;
	wait1Msec(time);
}
void chassisForward(int speed) {
	motor(LeftRear) = -speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = -speed;
}
void chassisBackwards(int speed) {
	motor(LeftRear) = speed;
	motor(RightRear) = speed;
	motor(LeftFront) = speed;
	motor(RightFront) = speed;
}
void chassisRight(int time, int speed) {
	motor(LeftRear) = speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = speed;
	motor(RightFront) = -speed;
	wait1Msec(time);
}
void chassisLeft(int time, int speed) {
	motor(LeftRear) = -speed;
	motor(RightRear) = speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = speed;
	wait1Msec(time);
}
// void TowerUp(int time, int speed) {
// 	motor(towerUp) = speed;
// 	motor(towerDown) = speed;
// 	wait1Msec(time);
// }
// void TowerDown(int time, int speed) {
// 	motor(towerUp) = -speed;
// 	motor(towerDown) = -speed;
// 	wait1Msec(time);
// }
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
void shoot() {
	motor(Gun) = 127;
}
void turn(int degrees) {
	int speed = 50;
	int fullRotationTime = 4000;
	int time = fullRotationTime/360*degrees;
	motor(LeftRear) = speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = speed;
	motor(RightFront) = -speed;
	wait1Msec(time);
	stopChassis();
}
void turnCounterClock(int degrees) {
	int speed = 50;
	int fullRotationTime = 5200;
	int time = fullRotationTime/360*degrees;
	motor(LeftRear) = -speed;
	motor(RightRear) = speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = speed;
	wait1Msec(time);
	stopChassis();
}

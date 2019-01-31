void stopChassis() {
	motor(LeftRear) = 0;
	motor(RightRear) = 0;
	motor(LeftFront) = 0;
	motor(RightFront) = 0;
	wait1Msec(100);
}

void stopTower() {
	motor(tower1) = 0;
	motor(tower2) = 0;
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
	motor(LeftRear) = 0;
	motor(RightRear) = 0;
	motor(LeftFront) = 0;
	motor(RightFront) = 0;
	motor(tower1) = 0;
	motor(tower2) = 0;
	motor(Intake) = 0;
	motor(Claw) = 0;
	motor(Gun) = 0;
	wait1Msec(time);
}


void chassisForward(int speed) {
	motor(LeftRear) = speed;
	motor(RightRear) = speed;
	motor(LeftFront) = speed;
	motor(RightFront) = speed;
}

void chassisBackwards(int speed) {
	motor(LeftRear) = -speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = -speed;
}

void clawUp() {
	motor(Claw) = 80;
}

void clawDown() {
	motor(Claw) = -80;
}

void intakeIn() {
	motor(Intake) = -120;
}

void intakeFlip() {
	motor(Intake) = 120;
}

void shoot() {
	motor(Gun) = 127;
}

void turn(int degrees) {
	int speed = 50;
	int fullRotationTime = 4450;
	int time = fullRotationTime/360*degrees;
	motor(LeftRear) = speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = speed;
	motor(RightFront) = -speed;
	wait1Msec(time);
	stopChassis();
}

void rotateSpeed(int speed) {
	motor(LeftRear) = -speed;
	motor(RightRear) = speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = speed;
}

void turnCounterClock(int degrees) {
	int speed = 50;
	int fullRotationTime = 4450;
	int time = fullRotationTime/360*degrees;
	motor(LeftRear) = -speed;
	motor(RightRear) = speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = speed;
	wait1Msec(time);
	stopChassis();
}

void towerDown() {
	motor(tower1) = -20;
	motor(tower2) = -20;
}

int adaptiveTurning(int speed, int degree) {
	int delta = abs(degree);
	if (delta < 45) {
		return 30;
	} else if (delta < 15) {
		return 10;
	}

	return speed;
}

void gyroTurnClockwise(int degrees) {
	writeDebugStreamLine("turning clockwise.");
	int currentSetting = getOrientation();
	//writeDebugStreamLine("currentSetting => %d", currentSetting);
	int targetSetting = (currentSetting - 10* degrees) % 3600;
	//writeDebugStreamLine("targetSetting => %d", targetSetting);
	int delta = abs(targetSetting - getOrientation());

	while(true) {
		int newDelta = abs(targetSetting - getOrientation());

		if (newDelta <= delta || delta > 200) {
			rotateSpeed(-adaptiveTurning(50, newDelta / 10));
			delta = newDelta;
			wait1Msec(10);
		} else {
			rotateSpeed(0);
			writeDebugStreamLine("stop turning");
			break;
		}
	}
}

void gyroTurnCounterClockwise(int degrees) {
	writeDebugStreamLine("turning counter clockwise.");
	int currentSetting = getOrientation();
	//writeDebugStreamLine("currentSetting => %d", currentSetting);
	int targetSetting = (currentSetting + 10* degrees) % 3600;
	//writeDebugStreamLine("targetSetting => %d", targetSetting);

	int delta = abs(targetSetting - getOrientation());
	while (true) {
		int newDelta = abs(targetSetting - getOrientation());

		if (newDelta <= delta || delta > 200) {
			rotateSpeed(adaptiveTurning(50, newDelta / 10));
			delta = newDelta;
			wait1Msec(10);
		} else {
			rotateSpeed(0);
			writeDebugStreamLine("stop turning");
			break;
		}
	}
}

int adaptiveSpeed(int speed, int matDistance) {
	if (matDistance < 5) {
		return 20;
	} else if (matDistance < 3) {
		return 15;
	}

	return speed;
}

void forwardEncoderAdaptiveSpeed(int matDistance, int speed, bool usingAdaptiveSpeed) {
	writeDebugStreamLine("move forward for %d mat distance.", matDistance);
	resetWheelEncoder();
	const int matEncoderRatio = 112;
	int currentSetting = getWheelEncoder();
	int targetSetting = matDistance * matEncoderRatio;
	writeDebugStreamLine("currentSetting = %d, targetSetting = %d", currentSetting, targetSetting);

	int delta = abs(targetSetting - getWheelEncoder());
	while (true) {
		int newDelta = abs(targetSetting - getWheelEncoder());

		if (newDelta <= delta || delta > 200) {
			writeDebugStreamLine("delta = %d, newDelta = %d", delta, newDelta);
			if (usingAdaptiveSpeed) {
				chassisForward(adaptiveSpeed(speed, newDelta / matEncoderRatio));
			} else {
				chassisForward(speed);
			}
			delta = newDelta;
			wait1Msec(10);
		} else {
			writeDebugStreamLine("delta = %d, newDelta = %d, stopping the chassis.", delta, newDelta);
			writeDebugStreamLine("final encoder value is %d before stopping.", getWheelEncoder());
			stopChassis();
			break;
		}
	}
}

void forwardEncoder(int matDistance, int speed) {
	forwardEncoderAdaptiveSpeed(matDistance, speed, true);
}

void backwardEncoderAdaptiveSpeed(int matDistance, int speed, bool usingAdaptiveSpeed) {
	writeDebugStreamLine("move backwards for %d mat distance.", matDistance);
	resetWheelEncoder();
	const int matEncoderRatio = -112;
	int currentSetting = getWheelEncoder();
	int targetSetting = matDistance * matEncoderRatio;
	writeDebugStreamLine("currentSetting = %d, targetSetting = %d", currentSetting, targetSetting);

	int delta = abs(targetSetting - getWheelEncoder());
	while (true) {
		int newDelta = abs(targetSetting - getWheelEncoder());

		if (newDelta <= delta || delta > 200) {
			writeDebugStreamLine("delta = %d, newDelta = %d", delta, newDelta);
			if (usingAdaptiveSpeed) {
				chassisBackwards(adaptiveSpeed(speed, abs(newDelta / matEncoderRatio));
			} else {
				chassisBackwards(speed);
			}
			delta = newDelta;
			wait1Msec(10);
		} else {
			writeDebugStreamLine("delta = %d, newDelta = %d, stopping the chassis.", delta, newDelta);
			writeDebugStreamLine("final encoder value is %d before stopping.", getWheelEncoder());
			stopChassis();
			break;
		}
	}
}

void backwardEncoder(int matDistance, int speed) {
	backwardEncoderAdaptiveSpeed(matDistance, speed, true);
}

void pause() {
	towerDown();
	wait1Msec(200);
	stopTower();
}

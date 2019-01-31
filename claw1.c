int clawThreshold = 20;

task claw1_control() {
	while (true) {
		if(abs(vexRt(Ch3Xmtr2)) > clawThreshold) {
			motor(claw) = vexRt(Ch3Xmtr2)
		} else if(abs(vexRt(Btn7UXmtr2)) == 1) {
			while(true) {
				if(getPotentiometer() < 2400) {
					motor(claw) = 127;
				} else if(getPotentiometer() > 2400) {
					motor(claw) = -50;
				} else {
					motor(claw) = 0;
				}
			}
		} else {
			motor(claw) = 0;
		}
	}
}

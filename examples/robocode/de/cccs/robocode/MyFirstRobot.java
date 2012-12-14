package de.cccs.robocode;

import java.awt.Color;

import robocode.BulletMissedEvent;
import robocode.Robot;
import robocode.ScannedRobotEvent;


public class MyFirstRobot extends Robot {
	boolean keepRotating = true;
	
	@Override
	public void run() {
		setRadarColor(Color.BLUE);
		setAdjustRadarForGunTurn(false);
		while (true) {
			if (keepRotating)
				turnGunLeft(10.0); else
				fire(1.0);
		}
	}
	
	@Override
	public void onBulletMissed(BulletMissedEvent event) {
		keepRotating = true;
	}
	
	@Override
	public void onScannedRobot(ScannedRobotEvent event) {
		keepRotating = false;
		fire(1.0);
	}
}

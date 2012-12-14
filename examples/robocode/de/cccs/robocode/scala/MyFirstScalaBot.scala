package de.cccs.robocode.scala

import robocode.robotinterfaces.peer.IBasicRobotPeer
import java.io.PrintStream
import robocode.Robot
import robocode.ScannedRobotEvent
import robocode.BulletMissedEvent

class MyFirstScalaBot extends Robot {
  var keepTurning = true
  
  override def run() : Unit = {
    setAdjustRadarForGunTurn(false)
    while (true) {
      if (keepTurning)
    	turnGunRight(5.0) else
    	fire(2.0)    	
    }
  }
  
  override def onBulletMissed(event : BulletMissedEvent) = {
    keepTurning = true
  }
  
  override def onScannedRobot(event : ScannedRobotEvent) : Unit = {
    keepTurning = false
  }
}
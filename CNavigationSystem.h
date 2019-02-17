/*
 * CNavigationSystem.h
 *
 *  Created on: Nov 8, 2016
 *      Author: nazow
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_
#include <iostream>
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"

class CNavigationSystem {
public:
	CNavigationSystem();

/*POI DB is created and connected to the Route.Other function of Navigation System is being called to enter the
	Waypoints and POIs to the route and to obtain the distance between the current location and the Next/Nearest POI*/
	void run();


private:
	CGPSSensor m_GPSSensor; 	//An Object of class CGPSSensor
	CRoute m_Route;				//An Object of class CRoute
	CPoiDatabase m_PoiDatabase; //An Object of class CPoiDatabase
	void enterRoute();//CWaypoint object's are declared and added to the Route
	void printRoute();
	void printDistanceCurPosNextPoi();/*// to calculate the distance between the Current location and
	  			   the Next/Nearest POI by calling the print method of
	  			   CRoute Class*/
};

#endif /* CNAVIGATIONSYSTEM_H_ */

/*
 * CNavigationSystem.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: nazow
 */

#include "CNavigationSystem.h"
#include "CWaypoint.h"
//using namespace std;
CNavigationSystem::CNavigationSystem() {
	cout << "Creating POI database ..." <<endl;

		// add some POIs to the database

	m_PoiDatabase.addPoi(Restaurant, "McDonalds", "McDonalds in Amsterdam", 52.4, 5.1);

	m_PoiDatabase.addPoi(Sightseeing, "Menlo Park", "Most beautiful park in the west side", 52.44, 7.5);

	m_PoiDatabase.addPoi(Sightseeing, "Hidelburg Castle","beautiful mountains are there", 20, 35);

	m_PoiDatabase.addPoi(Restaurant, "HDA Mensa", "Good one in Darmstadt", 53, 25.9);


	cout << "POI database has been created." << endl << endl;


}

void CNavigationSystem::enterRoute() {
	cout << "Creating a new route ..." << endl;


// create some Waypoints
	CWaypoint amsterdam("Amsterdam", 52.3667, 4.9);

CWaypoint berlin("Berlin", 52.5167, 13.3833);


// add the Waypoints to the route
	m_Route.addWaypoint(amsterdam);
	m_Route.addWaypoint(berlin);


// connect to the POI database
	m_Route.connectToPoiDatabase(&m_PoiDatabase);


// add some POIs to the route from the database
	m_Route.addPoi("McDonalds");

m_Route.addPoi("Menlo Park");
	m_Route.addPoi("Burger King");


cout << "The route has been created." << endl << endl;
}


void CNavigationSystem::printRoute() {
	m_Route.print();
}
void CNavigationSystem::printDistanceCurPosNextPoi() {
	// get current position from the GPS sensor
	cout << "====== Enter your current position ======" << endl;
	CWaypoint currPos = m_GPSSensor.getCurrentPosition();

	// print current position
	cout << "====== Current position ======" << endl;
	currPos.print(2);
	cout << endl;

	// find the nearest POI from current position
	cout << "======= Nearest POI from current position =========" << endl;
	double dist = m_Route.getDistanceNextPoi(currPos);
	cout << "Distance: " << dist << " Kilometers" <<endl;

}

void CNavigationSystem::run() {
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}







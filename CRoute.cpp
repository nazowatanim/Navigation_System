/*
 * CRoute.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: nazow
 */

#include "CRoute.h"

//using namespace std;

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {
	m_maxWp = maxWp;
	m_maxPoi = maxPoi;
	m_pWaypoint = new CWaypoint[m_maxWp];
	m_pPoi = new CPOI*[m_maxPoi];
	m_nextWp = 0;
	m_nextPoi = 0;
}

CRoute::CRoute(const CRoute &origin) {
	m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;
	m_pWaypoint = origin.m_pWaypoint;
	m_pPoi = origin.m_pPoi;
	m_nextWp = origin.m_nextWp;
	m_nextPoi = origin.m_nextPoi;
}


void CRoute::connectToPoiDatabase(CPoiDatabase *pPoiDB) {
	m_pPoiDatabase = pPoiDB;
}

void CRoute::addWaypoint(CWaypoint const &wp) {
	m_pWaypoint[m_nextWp++] = wp;
}

void CRoute::addPoi(string namePoi) {
	m_pPoi[m_nextPoi++] = m_pPoiDatabase->getPointerToPoi(namePoi);
}

double CRoute::getDistanceNextPoi(CWaypoint const &wp) {
	double minDist = 9999999999.0;
	int closestPOI = -1;

	for (int i = 0; i < m_nextPoi; i++) {
		double dist = m_pPoi[i]->calculateDistance(wp);
		if (dist < minDist) {
			minDist = dist;
			closestPOI = i;
		}
	}

	// print the closest POI
	m_pPoi[closestPOI]->print();

	return minDist;
}

void CRoute::print() {
	cout << "=========== Printing the route =============" << endl;
	cout << "List of Waypoints: " << endl;
	for (int i = 0; i < m_nextWp; i++) m_pWaypoint[i].print(1);

	cout << "List of POIs: " << endl;
	for (int i = 0; i < m_nextPoi; i++) m_pPoi[i]->print();

	cout << endl;
}


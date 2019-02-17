/*
 * CRoute.h
 *
 *  Created on: Nov 8, 2016
 *      Author: nazow
 */

#ifndef CROUTE_H_
#define CROUTE_H_



/*//this class provides the method to Navigation System to connect POI database,to add Waypoints and POIs to the route
to print the Waypoints POIs in the route. To claculate the distance beteen the location provided by the sensor and the nearest POI.*/

#include <iostream>
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPoiDatabase.h"


class CRoute {


public:
	CRoute(unsigned int maxWp, unsigned int nextWp);
	CRoute(CRoute const &origin);

	void connectToPoiDatabase(CPoiDatabase* pPoiDB);
	void addWaypoint(CWaypoint const &wp);
	void addPoi(string namePoi);
	double getDistanceNextPoi(CWaypoint const &wp);
	void print();
private:
	CWaypoint* m_pWaypoint; //pointer of type CWaypoint
	unsigned int m_maxWp; //holds value of max no of Waypoints
	unsigned int m_nextWp; //hold next index of Waypoint
	CPOI** m_pPoi; //double pointer
	unsigned int m_maxPoi;
	unsigned int m_nextPoi;
	CPoiDatabase* m_pPoiDatabase; //points to CPoiDatabase
};

#endif /* CROUTE_H_ */

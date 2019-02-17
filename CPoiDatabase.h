/*
 * CPoiDatabase.h
 *
 *  Created on: Nov 3, 2016
 *      Author: nazow
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_
#include "CPOI.h"

class CPoiDatabase {
public:
	CPoiDatabase();
	//add the POIs with its attributes type,name,description,latitude,longitude into POI database
	void addPoi(t_poi type,string name,string description,double latitude,double longitude);
	//Creates a pointer of type POIs based on the attributes name
	CPOI* getPointerToPoi(string name);
private:
	CPOI* m_poi[10]; //An array of type CPOI with length 10
	int m_nopoi;//holds the no of POI
};

#endif /* CPOIDATABASE_H_ */

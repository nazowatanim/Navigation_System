/*
 * CPoiDatabase.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: nazow
 */

#include "CPoiDatabase.h"
#include "CPOI.h"
#include <iostream>
using namespace std;

CPoiDatabase::CPoiDatabase()
{
	//initially there is no POI in database
m_nopoi=0;
}

void CPoiDatabase::addPoi(t_poi type,string name,string description,double latitude,double longitude)
{
	//CPOI newPOI(type,name,description,latitude,longitude);
	//if no of POI DB is less than zero then POI is entried in DB else an error message is printed
	if(m_nopoi<10)
	{
		m_poi[m_nopoi]=new CPOI(type,name,description,latitude,longitude);
		m_nopoi++;
	}
	else //error:if database exceeds
	{
		cout<<"Error:DB out of memory:CPOIDatabase can only hold 10points of interest"<<endl;
	}
}

/*creates a pointer of type CPOI for checking of POIs existence in the POI DB based on attribute name.
 * called by the addPOI method of  CRoute which adds POIs to Database
 */

 CPOI* CPoiDatabase::getPointerToPoi(string name)
{
//string p_name;
int i;
//POI Database is checked if it has a POI of same name
for(i=0;i<m_nopoi;i++)
{
	if(m_poi[i]->getName().compare(name)==0)
	{
		return m_poi[i];
	}

}
//if no match is found return NULL
return NULL;
}



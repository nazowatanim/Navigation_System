/*
 * CPOI.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: nazow
 */
#include <iostream>
#include "CPOI.h"
using namespace std;


CPOI::CPOI(t_poi type,string name,string description,double latitude,double longitude):CWaypoint(name,latitude,longitude)
{
	m_type=type;
	m_description=description;

}

/*to access the parameters of CWaypoint and copy the CWaypoint class
 * objects attributes into its passed variable references*/
void CPOI::getAllDatabyReference(string &name,double &latitude,double &longitude,t_poi &type,string &description)
{
	type=m_type;
	description=m_description;
	CWaypoint::getAllDatabyReference(name,latitude, longitude);
}
void CPOI::print()
{
	cout<<"Name: "<< m_name<<", ";
	cout<<"Description: "<<m_description<<", ";
	cout<<"Latitude: "<<m_latitude<<", ";
	cout<<"Longitude: "<<m_longitude<<endl;

}



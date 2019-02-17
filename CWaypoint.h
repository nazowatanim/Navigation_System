/*
 * CWaypoint.h
 *
 *  Created on: Oct 30, 2016
 *      Author: nazow
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_


#include <string>
using namespace std;

#define DEGREE 1  //print format degree
#define mmss 2   //print format deg mm ss
#define R 6378  //radius of earth
#define PI 3.1415926
#define SHOWADDRESS

class CWaypoint {
public:
	CWaypoint(string name,double latitude=0,double longitude=0);
    /*it will set the data to our object*/
	void set(string name,double latitude,double longitude);
	string getName();
	double getLatitude();
	double getLongitude();
	/*to calculate the distance between two points*/
	double calculateDistance(const CWaypoint& wp);
	void print(int format);
	/*to get the values by reference*/
	void getAllDatabyReference(string &name,double &latitude,double &longitude);

	/*protected variables*/
protected:
	string m_name;
	double m_latitude;
	double m_longitude;

	/*private methods;*/
private:
	/*to convert the latitude to deg mm ss format*/
	void transformLatitude2degmmss(int &deg,int &mm,double &ss);
	/*to convert the longitude to deg mm ss format*/
	void transformLongitude2degmmss(int &deg,int &mm,double &ss);

};

#endif /* CWAYPOINT_H_ */

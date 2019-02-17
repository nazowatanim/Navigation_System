/*
 * CGPSSensor.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: nazowa
 */


#include<iostream>
#include "CGPSSensor.h"
#include "CWaypoint.h"
using namespace std;

CGPSSensor::CGPSSensor()
{
	// TODO Auto-generated constructor stub
}

CWaypoint CGPSSensor::getCurrentPosition()
{
string name;
double Latitude,Longitude;
cout<<"Enter Latitude"<< endl;
cin>>Latitude;
cout<<"Enter Longitude"<<endl;
cin>>Longitude;
CWaypoint CurrentPos(name,Latitude,Longitude);
return CurrentPos;
}





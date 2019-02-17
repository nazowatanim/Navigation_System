/*
 * main.cpp
 *
 *  Created on: Oct 30, 2016
 *      Author: nazow
 */

#include<iostream>
#include "CWaypoint.h"
#include "CGPSSensor.h"
#include "CPOI.h"
#include "CPOIDatabase.h"
#include "CRoute.h"
#include "CNavigationSystem.h"

#include "CWaypoint.h"

int main(void)
{
	//implementation of 1.1(d)
	CWaypoint Amsterdam("Amsterdam",52.3667,4.9);
	CWaypoint Darmstadt("Darmstadt",49.8667,8.65);
	CWaypoint Berlin("Berlin",52.5167,1.3833);
	CWaypoint Tokyo("Tokyo",36.6833,139.6833);
	CWaypoint newWayoint();

	//implementing 1.1 (e)
	Berlin.print(1);
	Berlin.print(2);
 //best file to use define is header file
	 //implementation of 1.1(g)
	string name=Amsterdam.getName();
	cout<<name<<endl;
	double latitude=Amsterdam.getLatitude();
	cout<<latitude<<endl;
	double longitude=Amsterdam.getLongitude();
	cout<<longitude<<endl;
	// implementation of 1.1(h)
	Tokyo.getAllDatabyReference(name,latitude,longitude);
	/*address of parameters
	address of name:0x6afef0
	address of latitude:0x6afe10
	address of longitude: 0x6afe08*/

	cout<<"address of name is "<<&name<<endl;
	cout<<"address of latitude is "<<&latitude<<endl;
	cout<<"address of longitude is "<<&longitude<<endl;

/*
	output-address of local variable
	//	address of name is 0x6afe7c
	//	address of latitude is 0x6afe70
	//	address of longitude is 0x6afe68
*/
 //implementation of 1.1(i)
	Amsterdam.calculateDistance(Berlin);
	Berlin.calculateDistance(Tokyo);

	cout<<"======Running the Navigation System========="<<endl;
	CNavigationSystem NaviSys;
	NaviSys.run();


}





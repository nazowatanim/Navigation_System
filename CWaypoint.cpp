/*
 * CWaypoint.cpp
 *
 *  Created on: Oct 30, 2016
 *      Author: nazow
 */

#include <iostream>
#include "CWaypoint.h"
#include <math.h>
#include "CGPSSensor.h"

/*method implementation */
//Constructor
 CWaypoint::CWaypoint(string name,double latitude,double longitude)
 {
	 set(name,latitude,longitude);  //set the parameter values
#ifdef SHOWADDRESS
	 {
	 cout<<"constructor generates object at" << this<<endl;
	 //prints the attributes value and its corresponding address
	 cout<<"name"<<m_name<<"is at "<<&name<<"  data occupied is "<<sizeof(name)<<endl;
	 cout<<"latitude"<<m_latitude<< "is at "<<&latitude<<"  data occupied is "<<sizeof(latitude)<<endl;
	 cout<<"longitude"<<m_longitude<< "is at "<<&longitude<<"  data occupied is "<<sizeof(longitude)<<endl;
	 }
#endif
	 }
 //implemeting set method
 void CWaypoint::set(string name,double latitude,double longitude)
 {
	 m_name=name;
	 //setting the valid range for latitude -90 to +90
	 if (latitude>=-90&& latitude<=90)
	 {
		 m_latitude=latitude;
	}
	 else {
		 m_latitude=0;
	 }
	 //setting the valid range for latitude -180 to +180
	 if(longitude>=-180 && longitude<=180)
	 {
		 m_longitude=longitude;
	 }
	 else
	 {
		 m_longitude=0;
	 }

 }
 // returns name,latitude,longitude
 string CWaypoint::getName()
 {
	 return m_name;
 }
 double CWaypoint::getLatitude()
 {
	 return m_latitude;
 }
 double CWaypoint::getLongitude()
 {
 return m_longitude;
 }

 void CWaypoint::getAllDatabyReference( string &name,double &latitude,double &longitude)
 {
 name=m_name;
 latitude=m_latitude;
 longitude=m_longitude;
 }

 //method to calculate distance
 double CWaypoint::calculateDistance(const CWaypoint& wp)
 {
 double distance;
 distance= R
         * acos(
                 sin(m_latitude * (PI / 180))
                         * sin(wp.m_latitude * (PI / 180))
                         + cos(m_latitude * (PI / 180))
                                 * cos(wp.m_latitude * (PI / 180))
                                 * cos(
                                         (wp.m_longitude - m_longitude)
                                                 * (PI / 180)));
 cout<<"Distance between "<<m_name<< " & "<< wp.m_name << " is "<<distance<<endl;

 return distance;
 }
 //Print method to print the values

 void CWaypoint::transformLatitude2degmmss(int &deg,int &mm,double &ss)
 {
	 deg=int(m_latitude);
	 mm=(m_latitude-deg)*60;
	 ss=double(((m_longitude-deg)*60)-mm)*60;
 }
 ///Longitude
 void CWaypoint::transformLongitude2degmmss(int &deg,int &mm,double &ss)
  {
 	 deg=int(m_longitude);
 	 mm=(m_longitude-deg)*60;
 	 ss=double(((m_latitude-deg)*60)-mm)*60;
  }

 void CWaypoint::print(int format)
 {

     int deg, mm;
     double ss;

     //Prints in Degree

     switch (format)
     {
     case 1:
     {

   cout << "" << m_name << " on latitude " << m_latitude << " and longitude " << m_longitude << " " << endl;

         break;
     }

         //Prints in deg mm ss
     case 2:
     {
         transformLatitude2degmmss(deg, mm, ss);
         cout << " " << m_name << "  on latitude " << deg << " deg " << mm<< "min " << ss << "s";

         transformLongitude2degmmss(deg, mm, ss);

         cout << " and longitude " << deg << "deg " << mm << "min " << ss
                 << "s " << endl << endl;

         break;
     }
     default:
     {
    	 break;
     }
     }

 }



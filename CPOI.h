/*
 * CPOI.h
 *
 *  Created on: Nov 3, 2016
 *      Author: nazow
 */

#ifndef CPOI_H_
#define CPOI_H_
#include "CWaypoint.h"
enum t_poi{Restaurant,Sightseeing,Club,Nature,Mall};

class CPOI :public CWaypoint
{
public:


	/*prints the attribute type,description and also inherited attributes(name,lat,long) from base class*/
	void print();
	CPOI(t_poi type,string name,string description,double latitude,double longitude);
	/*takes name,lat,long,description and copies into reference passed*/
	void getAllDatabyReference(string &name,double &latitude,double &longitude,t_poi &type,string &description);

private:
t_poi m_type;
string m_description;

};



#endif /* CPOI_H_ */

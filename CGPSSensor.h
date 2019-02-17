/*
 * CGPSSensor.h
 *
 *  Created on: Nov 2, 2016
 *      Author: nazowa
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_
#include "CWaypoint.h"

class CGPSSensor
{
public:
	CGPSSensor();
	CWaypoint getCurrentPosition();//get current position from the user

};

#endif /* CGPSSENSOR_H_ */

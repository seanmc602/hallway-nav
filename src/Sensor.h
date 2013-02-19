/*
 * Sensor.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Sean Cardello
 */

#ifndef SENSOR_H_
#define SENSOR_H_

namespace navmodel
{

class Sensor
{
public:
	virtual ~Sensor();
	virtual void sense() = 0;
};
}

#endif /* SENSOR_H_ */

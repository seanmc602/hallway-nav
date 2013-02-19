/*
 * SharpInfraredProximitySensor.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Sean Cardello
 */

#ifndef SHARPINFRAREDPROXIMITYSENSOR_H_
#define SHARPINFRAREDPROXIMITYSENSOR_H_

#include "Sensor.h"

namespace navmodel
{

class SharpInfraredProximitySensor : public Sensor
{
private:
	int distance;

public:
	// Public constants
	static const int MIN_DISTANCE = 20; // cm
	static const int MAX_DISTANCE = 150; // cm

	SharpInfraredProximitySensor()
	{
		distance = -1;
	}

	virtual ~SharpInfraredProximitySensor() = 0;

	// Override sense method
	void sense(void)
	{
		// TODO: Interact with Person and World to obtain a distance.
	}

	// Public functions
	int getDistance(void)
	{
		return distance;
	}
};
}

#endif /* SHARPINFRAREDPROXIMITYSENSOR_H_ */

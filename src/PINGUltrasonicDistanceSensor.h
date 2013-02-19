/*
 * PINGUltrasonicDistanceSensor.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Sean Cardello
 */

#ifndef PINGULTRASONICDISTANCESENSOR_H_
#define PINGULTRASONICDISTANCESENSOR_H_

#include "Sensor.h"

namespace navmodel
{

class PINGUltrasonicDistanceSensor : public Sensor
{
private:
	bool trigger;
	int distance; // in cm

public:
	// Public constants
	static const int MIN_DISTANCE = 2; // cm
	static const int MAX_DISTANCE = 300; // cm

	PINGUltrasonicDistanceSensor()
	{
		trigger = false;
		distance = -1;
	}

	virtual ~PINGUltrasonicDistanceSensor() = 0;

	// Override sense method
	void sense(void)
	{
		if (trigger)
		{
			// TODO: Interact with Person and World to obtain a distance.
			distance = 0;
		}
	}

	// Public functions
	void setTrigger(bool enable)
	{
		trigger = enable;
		if (!enable) distance = -1;
	}

	int getDistance(void)
	{
		return distance;
	}
};
}

#endif /* PINGULTRASONICDISTANCESENSOR_H_ */

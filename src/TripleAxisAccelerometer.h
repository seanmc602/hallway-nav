/*
 * TripleAxisAccelerometer.h
 *
 *  Created on: Feb 18, 2013
 *      Author: Sean Cardello
 */

#ifndef TRIPLEAXISACCELEROMETER_H_
#define TRIPLEAXISACCELEROMETER_H_

#include "Person.h"

namespace navmodel
{

enum Sensitivity
{
	OneFiveG,
	SixG
};

typedef struct Accel
{
	float X;
	float Y;
	float Z;
};

class TripleAxisAccelerometer
{
private:
	Accel acceleration;
	bool sleep;
	bool zero_g;
	Sensitivity g_mode;
	Person *person;

public:
	TripleAxisAccelerometer(Person *p)
	{
		person = p;
		acceleration.X = acceleration.Y = acceleration.Z = 0.0;
		sleep = true;
		zero_g = false;
		g_mode = OneFiveG;
	}

	virtual ~TripleAxisAccelerometer() = 0;

	void sense(void)
	{
		if (!sleep)
		{
			acceleration.X = person->x_accel.read();
			acceleration.Y = person->y_accel.read();
			acceleration.Z = person->z_accel.read();
		}
	}

	Accel *getAcceleration(void)
	{
		return &acceleration;
	}

	void setSleep(bool enable)
	{
		sleep = enable;
	}

	void setGMode(Sensitivity m)
	{
		g_mode = m;
	}

	Sensitivity getGMode(void)
	{
		return g_mode;
	}

	bool isZeroG(void)
	{
		return zero_g;
	}

	bool isAsleep(void)
	{
		return sleep;
	}
};
}

#endif /* TRIPLEAXISACCELEROMETER_H_ */

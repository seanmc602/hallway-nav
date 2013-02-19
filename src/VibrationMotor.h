/*
 * VibrationMotor.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Owner
 */

#ifndef VIBRATIONMOTOR_H_
#define VIBRATIONMOTOR_H_

namespace navmodel
{

class VibrationMotor
{
private:
	// Private constants
	static const float VIBRATION_RANGE = 0.8; // G

	static float scaleVibration; // G / V
	float vibration;

public:
	// Private constants
	static const float MIN_VOLTAGE = 2.5;
	static const float MAX_VOLTAGE = 3.8;

	VibrationMotor()
	{
		vibration = 0.0;
		scaleVibration = VIBRATION_RANGE / (MAX_VOLTAGE - MIN_VOLTAGE);
	}

	virtual ~VibrationMotor() = 0;

	void setVoltage(float v)
	{
		if (v >= MIN_VOLTAGE && v <= MAX_VOLTAGE)
		{
			vibration = v * scaleVibration;
		}
	}

	float getVibration()
	{
		return vibration;
	}
};
}

#endif /* VIBRATIONMOTOR_H_ */

/*
 * Person.h
 *
 *  Created on: Feb 18, 2013
 *      Author: Owner
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <systemc.h>

namespace navmodel
{

SC_MODULE(Person)
{
	sc_in< sc_int<16> > x;
	sc_in< sc_int<16> > y;
	sc_in< sc_int<16> > theta;

	sc_out< sc_int<16> > x_accel;
	sc_out< sc_int<16> > y_accel;
	sc_out< sc_int<16> > z_accel;

	void move()
	{
		// TODO: simulate moving acceleration;
		x_accel.write(1.234);
		y_accel.write(2.345);
		z_accel.write(3.456);
	}

	SC_CTOR(Person)
	{
		SC_METHOD(move);
		sensitive << x;
		sensitive << y;
		sensitive << theta;
	}
};
}

#endif /* PERSON_H_ */

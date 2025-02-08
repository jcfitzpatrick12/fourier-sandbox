#include <iostream>
#include <cmath>

#include "rect.h"
#include "types.h"
#include "base_periodic_signal.h"

Rect::Rect(const double period,
	   const int num_samples)
	: BasePeriodicSignal(period, num_samples)
{
	initialise_samples();
}

Rect::~Rect() {}

const complex_vector Rect::compute_samples() const 
{
	// Initialise a vector to hold the complex samples
	complex_vector signal(_num_samples, complex_double(0,0));

	// Extract the physical time associated with each sample
	real_vector times { this->get_times()  };

	// Set the output signal to be the rect function, with width 1, centred at the midpoint time.
	for (int i { 0 }; i < _num_samples; i++)
	{
		if ( fabs( times[i] ) <= 0.5 )
		{
			signal[i] = {1, 0};
		}	
	}
	return signal;
}

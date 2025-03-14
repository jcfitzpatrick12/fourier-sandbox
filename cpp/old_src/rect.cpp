#include "rect.h"
#include "types.h"
#include "base_signal.h"

#include <iostream>
#include <cmath>

Rect::Rect(const double duration,
	   const int num_samples)
     : BaseSignal(duration, num_samples)
{ compute_samples(); }

Rect::~Rect() {}

void Rect::compute_samples()
{
	// Extract the physical time associated with each sample
	real_vector times { this->get_times()  };

	// Set the output signal to be the rect function, with width 1, centred at the midpoint time.
	for (int i { 0 }; i < _num_samples; i++)
	{
		if ( fabs( times[i] ) <= 0.5 )
		{
			_samples[i] = {1, 0};
		}	
	}
}

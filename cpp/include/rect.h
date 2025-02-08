#ifndef RECT_H
#define RECT_H

#include "base_periodic_signal.h"
#include "types.h"

class Rect : public BasePeriodicSignal
{
public:
	Rect(const double period,
	     const int num_samples);
	~Rect();
	const complex_vector compute_samples() const override;
};

#endif

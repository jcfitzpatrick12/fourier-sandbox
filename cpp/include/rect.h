#ifndef RECT_H
#define RECT_H

#include "types.h"
#include "base_signal.h"

class Rect : public BaseSignal
{
public:
	Rect(const double duration,
	     const int num_samples);
	~Rect();
	void compute_samples() override;
};

#endif

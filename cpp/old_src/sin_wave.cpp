#include "base_signal.h"
#include "sin_wave.h"
#include "types.h"

#include <cmath>

SinWave::SinWave(const double duration,
		 const int num_samples)
	: BaseSignal(duration, num_samples)
{ compute_samples(); }

SinWave::~SinWave() {}

void SinWave::compute_samples()
{
    // Populate according to a sin wave periodic with period T
    for (int n {0}; n < _num_samples; ++n)
    {
        double sin_arg { 2 * M_PI * get_time(n) / _duration };
        _samples[n] = { std::sin(sin_arg), 0.0 };
    }
}

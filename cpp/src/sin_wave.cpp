#include <cmath>

#include "sin_wave.h"
#include "types.h"

SinWave::SinWave(const double period,
                 const int num_samples) 
        : BasePeriodicSignal(period, num_samples)
{
    initialise_samples();
}

const complex_vector SinWave::compute_samples() const
{
    // Initialise a vector that to hold the complex samples
    complex_vector signal(_num_samples, complex_double(0, 0));

    // Populate according to a sin wave periodic with period T
    for (int n {0}; n < _num_samples; ++n)
    {
        complex_double z { 2 * M_PI * get_time(n) / _period };
        signal[n] = std::sin(z);
    }
    return signal;
}
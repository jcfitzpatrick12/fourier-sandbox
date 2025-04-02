#include "signal_factory.h"
#include "base_signal.h"
#include "types.h"

SampledSignal sample_signal(const real_vector& points, 
		            const BaseSignal& signal)
{
    long unsigned int num_samples { points.size() };
    complex_vector samples(num_samples, complex_double(0,0));
    for (int k {0}; k < num_samples; k++)
    {
        samples[k] = signal.compute_sample( points[k] );
    }    
    return SampledSignal(points, samples);
}

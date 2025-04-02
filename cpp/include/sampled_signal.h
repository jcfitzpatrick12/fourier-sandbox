#ifndef SAMPLED_SIGNAL_H
#define SAMPLED_SIGNAL_H

#include "types.h"

// Encapsulate a signal sampled at a discrete set of points in it's domain.
class SampledSignal
{
public:
    SampledSignal(const real_vector points,
		  const complex_vector samples);
    ~SampledSignal();

    // Get the points in the domain at which each sample was evaluated.
    const real_vector& get_points() const;

    // Get the sample values at each point in the domain.
    const complex_vector& get_samples() const;

    // Get the total number of samples.
    int get_num_samples() const;

    // Get the sample rate of the signal.
    double get_sample_rate() const;
	
    // Get the sample interval - the reciprocal of the sample rate.
    double get_sample_interval() const;

    // Get the point in the domain according to the sample index.
    double get_point(const int sample_index) const;
    
    // Get the sample value according to the sample index.
    complex_double get_sample(const int sample_index) const;

    // Get the size of the sampled interval in the domain
    double get_range() const;

private:
    // Compute the sample rate of the signal.
    const double compute_sample_rate() const;
    // Compute the number of samples.
    const int compute_num_samples() const;

    const real_vector points_;
    const complex_vector samples_;
    const int num_samples_;
    const double sample_rate_;
}; 

#endif

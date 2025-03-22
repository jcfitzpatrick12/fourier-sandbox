#include "types.h"
#include "constants.h"
#include "sampled_signal.h"

#include <cmath>

SampledSignal::SampledSignal(const real_vector points,
		             const complex_vector samples)
	      : points_(points),
	        samples_(samples),
		num_samples_( compute_num_samples() ),
		sample_rate_( compute_sample_rate() )

{
    if (points_.size() != samples_.size())
    {
        throw std::runtime_error("There must be exactly one sample value for every "
			         "point in the domain.");
    }
}

SampledSignal::~SampledSignal()
{}

const real_vector& SampledSignal::get_points() const
{
    return points_;
}

const complex_vector& SampledSignal::get_samples() const
{
    return samples_;
}

int SampledSignal::get_num_samples() const
{
    return num_samples_;
}

double SampledSignal::get_sample_rate() const  
{
    return sample_rate_;
}

double SampledSignal::get_point(const int sample_index) const
{
    return points_[sample_index];
}

const double SampledSignal::compute_sample_rate() const
{
    int num_differences { get_num_samples() - 1};
    real_vector diffs(num_differences, 0);
    // First find the explicit differences between each sample.
    for (int k {0}; k < num_differences; k++)
    {
        diffs[k] = points_[k+1] - points_[k];
    }
    
    // Ensure they are equidistant, up to a tolerance.
    for (double diff : diffs)
    {
        if (fabs(diff - diffs[0]) > EPSILON)
	{
            throw std::logic_error("Expected a constant sampling rate!");
	}	
    }
    return (1.0f / diffs[0]);
}

const int SampledSignal::compute_num_samples() const
{
    return samples_.size();
}


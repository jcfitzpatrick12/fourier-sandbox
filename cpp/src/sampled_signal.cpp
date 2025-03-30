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

    if (points_.size() < 1 )
    {
        throw std::runtime_error("There must be at least one sampled point in the domain.");
    }

    for (int i {1}; i < points_.size(); i++) {
        if (points_[i] <= points_[i-1]) {
            throw std::runtime_error("Points in the domain must be strictly increasing.");
        }
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

double SampledSignal::get_sample_interval() const
{
    return 1/sample_rate_;
}

double SampledSignal::get_point(const int sample_index) const
{
    return points_[sample_index];
}


complex_double SampledSignal::get_sample(const int sample_index) const
{
    return samples_[sample_index];
}


double SampledSignal::get_range() const
{
    return (points_.back() - points_.front());
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


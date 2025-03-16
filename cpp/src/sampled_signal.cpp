#include "types.h"
#include "sampled_signal.h"

SampledSignal::SampledSignal(const real_vector points,
		             const complex_vector samples)
	      : points_(points),
	        samples_(samples),
		num_samples_( compute_num_samples() ),
		sample_rate_( compute_sample_rate() )

{}

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

double SampledSignal::get_time(const int sample_index) const
{
    return 0.0f;
}

const double SampledSignal::compute_sample_rate() const
{
    return 0.0f;
}

const int SampledSignal::compute_num_samples() const
{
    return 0;
}


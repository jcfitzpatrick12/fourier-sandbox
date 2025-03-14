#include "base_signal.h"
#include "types.h"
#include "constants.h"

#include <vector>
#include <complex>
#include <cmath>

BaseSignal::BaseSignal(const double duration,
		       const int num_samples)
	   : _duration(duration),
	     _num_samples(num_samples),
	     _times( compute_times() ),
	     _sample_rate( compute_sample_rate() ),
	     _samples( complex_vector(_num_samples,0.0) ) 
{}


BaseSignal::~BaseSignal() 
{}


const double BaseSignal::get_duration() const
{
    return _duration;
}


const int BaseSignal::get_num_samples() const
{
    return _num_samples;
}


const real_vector& BaseSignal::get_times() const
{
    return _times;
}


const int BaseSignal::get_sample_rate() const
{
    return _sample_rate;
}


const complex_vector& BaseSignal::get_samples() const
{
    return _samples;
}


// Times are centred at zero, meaning that if the number
// of samples per second is odd, the midpoint will be at
// t=0.
const double BaseSignal::get_time(const int sample_index) const
{
    return _duration * (static_cast<double>(sample_index) / _num_samples) - (_duration / 2.0);
}


const real_vector BaseSignal::compute_times()
{
    real_vector times(_num_samples, 0);
    
    for (int k {0}; k < _num_samples; k++)
    {
	times[k] = get_time(k);
    }
    return times;
}


const double BaseSignal::compute_sample_rate() const
{
    int num_differences = get_num_samples() - 1;
    real_vector delta_ts(num_differences, 0);

    // Find the explicit differences between each sample,
    // making no assumption that they are equidistant.
    
    for (int k {0}; k < num_differences; k++)
    {
        delta_ts[k] = _times[k+1] - _times[k];
    } 

    // Ensure they are equidistant (up to a tolerance, comparing
    // doubles...
    for (double delta_t : delta_ts)
    {
        if (fabs(delta_t - delta_ts[0]) > EPSILON)
	{
	    throw std::logic_error("Expected a constant time difference!");
	}
    }

    return (1 / delta_ts[0]);
}

#include <vector>
#include <complex>

#include "base_periodic_signal.h"
#include "types.h"
#include "constants.h"

BasePeriodicSignal::BasePeriodicSignal(const double period,
                                       const int num_samples)
                   : _period(period),
                     _num_samples(num_samples),
                     _times( compute_times() ),
                     _samples( complex_vector(_num_samples, 0.0) )
                     {}


BasePeriodicSignal::~BasePeriodicSignal() {}


const int BasePeriodicSignal::get_num_samples() const
{
    return _num_samples;
}

const double BasePeriodicSignal::get_period() const
{
    return _period;
}


const real_vector& BasePeriodicSignal::get_times() const
{
    return _times;
}


const complex_vector& BasePeriodicSignal::get_samples() const
{
    return _samples;
}


// Compute the physical time associated with a sample at a particular index.
// The times are centred around zero, meaning that if the number of samples
// per period is odd, the midpoint sample will be at t=0.
const double BasePeriodicSignal::get_time(const int sample_index) const
{
    return _period * (static_cast<double>(sample_index) / _num_samples) - (_period / 2.0);
}


const double BasePeriodicSignal::get_samp_rate() const
{
    int num_differences = get_num_samples() - 1;
    real_vector delta_ts(num_differences, 0);

    // Find the explicit differences between each physical time. 
    // Makes no assumptions on whether they are equidistant.
    for (int k {0}; k < num_differences; ++k)
    {
        delta_ts[k] = _times[k+1] - _times[k];
    }

    // Ensure they are equidistant
    for (double delta_t : delta_ts)
    {
        if (fabs(delta_t - delta_ts[0]) > EPSILON)
        {
            throw std::logic_error("Expected constant time difference!");
        }
    }
    
    // Return the (ensured constant) sampling rate
    return (1 / delta_ts[0]);

}

void BasePeriodicSignal::initialise_samples() 
{
    _samples = compute_samples();
}


const real_vector BasePeriodicSignal::compute_times()
{

    real_vector times(_num_samples, 0 );

    for (int k {0}; k < _num_samples; ++k)
    {
        times[k] = get_time(k);
    }

    return times;
};


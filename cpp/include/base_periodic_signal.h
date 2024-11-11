#ifndef BASE_PERIODIC_SIGNAL_H
#define BASE_PERIODIC_SIGNAL_H

#include "types.h"

// Define a periodic signal over the interval [0, T)
// through discrete samples evaluated by derived classes.
class BasePeriodicSignal
{
public:

    // Base class constructor.
    BasePeriodicSignal(const double period, 
                       const int num_samples);

    // Base class destructor.
    virtual ~BasePeriodicSignal();
    
    // Get the total number of samples in the signal.
    const int get_num_samples() const;

    // Get the period of the signal.
    const double get_period() const;

    // Get a vector of the physical times associated with each sample
    const real_vector& get_times() const;

    // Get the physical time associated with the index of a sample.
    const double get_time(const int sample_index) const;

    // Get a vector of the complex periodic signal samples.
    const complex_vector& get_samples() const;

    // Get the (ensured constant) sampling rate
    const double get_samp_rate() const;


protected:
    const int _num_samples;
    const double _period;
    const real_vector _times;
    complex_vector _samples;

    // Compute an array assigning physical times to each sample.
    // Assumes samples are taken equidistantly over the period.
    const real_vector compute_times();

    // Compute each of the complex sample values.
    // Pure virtual member function must be implemented by a derived class.
    virtual const complex_vector compute_samples() const = 0;

    // Used to set the signal member variable in the derived classes constructor.
    void initialise_samples();

};

#endif

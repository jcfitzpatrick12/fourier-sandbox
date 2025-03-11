#ifndef BASE_SIGNAL_H
#define BASE_SIGNAL_H

#include "types.h"

// Define a signal over the interval [-`duration`/2,  `duration`/2)
// Sample values are computed by derived classes.
class BaseSignal
{
public:
    // Base class constructor
    BaseSignal(const double duration,
	       const int num_samples);
   
    // Virtual destructor for polymorphic base class.	    
    virtual ~BaseSignal();
    
    // Get the duration of the signal.
    const double get_duration() const;

    // Get the total number of samples in the signal.
    const int get_num_samples() const;

    // Get the physical times associated with each sample.
    const real_vector& get_times() const;

    // Get the sample rate
    const int get_sample_rate() const;

    // Get the physical time associated with the index of a sample.
    const double get_time(const int sample_index) const; 

    // Get the sample values.
    const complex_vector& get_samples() const;

    // Get the sample rate.
    const double compute_sample_rate() const;

protected:
    const double _duration;
    const int _num_samples;
    const real_vector _times;
    const double _sample_rate;
    // Non-constant, as it must be initialised by the
    // derived class.
    complex_vector _samples;

    // Compute the physical times associated with each sample.
    const real_vector compute_times();

    // Compute the sample values.
    // Pure virtual member function must be implemented by derived classes.
    virtual void compute_samples() = 0;
};

#endif

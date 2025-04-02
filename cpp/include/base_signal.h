#ifndef BASE_SIGNAL_H
#define BASE_SIGNAL_H

#include "types.h"

// Interface to implement a complex valued signal, either in the time domain, or the frequency domain.
class BaseSignal
{
public:
    BaseSignal();
    // Virtual destructor for a polymorphic base class.
    virtual ~BaseSignal();
    // Compute the sample value at some (real valued) point in the domain.
    virtual complex_double compute_sample(double point) const = 0;

};

#endif

#ifndef SIGNAL_FACTORY_H
#define SIGNAL_FACTORY_H

#include "base_signal.h"

// Each signal type corresponds to an implementation of a periodic signal.
enum SignalType 
{
    sin_wave,
    rect
};

// Periodic signal factory..
std::unique_ptr<const BaseSignal> make_signal(const SignalType signal_type,
					      const double duration,
					      const int num_samples);

#endif

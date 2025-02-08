#ifndef SIGNAL_FACTORY_H
#define SIGNAL_FACTORY_H

#include "base_periodic_signal.h"

// Each signal type corresponds to an implementation of a periodic signal.
enum SignalType 
{
	sin_wave,
	rect
};

// Periodic signal factory..
std::unique_ptr<const BasePeriodicSignal> make_periodic_signal(const SignalType signal_type,
					      		       const double period,
					                       const int num_samples);

#endif

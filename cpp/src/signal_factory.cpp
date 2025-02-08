#include <memory>

#include "signal_factory.h"
#include "base_periodic_signal.h"
#include "sin_wave.h"
#include "rect.h"

std::unique_ptr<const BasePeriodicSignal> make_periodic_signal(const SignalType signal_type, 
					      		       const double period,
					                       const int num_samples)
{
	switch (signal_type)
	{
		case SignalType::sin_wave:	
			return std::make_unique<SinWave>(period, num_samples);
		case SignalType::rect:
			return std::make_unique<Rect>(period, num_samples);
		default:
			throw std::invalid_argument("Received an unrecognised signal type.");	
	}	
}

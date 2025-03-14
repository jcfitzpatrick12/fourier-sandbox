#include "signal_factory.h"
#include "base_signal.h"
#include "sin_wave.h"
#include "rect.h"

#include <memory>

std::unique_ptr<const BaseSignal> make_signal(const SignalType signal_type, 
				     	      const double duration,
					      const int num_samples)
{
	switch (signal_type)
	{
		case SignalType::sin_wave:	
			return std::make_unique<SinWave>(duration, num_samples);
		case SignalType::rect:
			return std::make_unique<Rect>(duration, num_samples);
		default:
			throw std::invalid_argument("Received an unrecognised signal type.");	
	}	
}

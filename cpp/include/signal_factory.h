#ifndef SIGNAL_FACTORY_H 
#define SIGNAL_FACTORY_H 

#include "base_signal.h"
#include "sampled_signal.h"
#include "types.h"
#include "rect.h"

#include <memory>

// Create a const for each derived signal class.
enum SignalType
{
    rect
};


// Make a signal, for defined signal types.
template <typename... Args>
std::unique_ptr<const BaseSignal> make_signal(SignalType signal_type, Args&&... args) 
{
    switch (signal_type) {
        case SignalType::rect:
            return std::make_unique<Rect>(std::forward<Args>(args)...);
	default:
	    throw std::invalid_argument("Unrecognised signal type.");
    }
}


// Sample a signal.
std::unique_ptr<const SampledSignal> sample_signal(const real_vector& points, std::unique_ptr<const BaseSignal> signal);


#endif

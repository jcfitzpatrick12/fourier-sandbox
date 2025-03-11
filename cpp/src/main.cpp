// Refactor "BaseSignal"
// 	-> Seperate out the "continous" functionality, from the "sampling" functionality...
// 	-> Now, represents almost the "continous" f(t), in the sense that you give it a t, and it will compute the sample
// 	value. That's all...
// 	-> Change the responsibility of `compute_samples` - just evaluate the sample value at time `t`!
// 	-> Make `compute_samples` - or whatever it's new analogue is now called - public.
// Remove "sampling" from `BaseSignal`, and instead delegate this to a new function and return class.
// 	-> Perhaps the return is "SampledSignal"
// 	-> So we have seperated some concerns from our current `BaseSignal`...
// Refactor the rest of the code in line with these changes.
// Now, the `extend` functionality should be easier/clearer to implement.
// Write a function which computes the F.T. via the triangle trick.
// Compare F.T. to F.S. and plot, to make sure the code is working...
#include "base_signal.h"
#include "signal_factory.h"
#include "fourier.h"

#include <memory>
#include <iostream>
#include <cmath>


real_vector make_frequencies(const int num_freq_samples,
		             const double min_freq,
			     const double max_freq)
{
    real_vector frequencies(num_freq_samples);
    for (int n {0}; n < num_freq_samples; n++)
    {
        frequencies[n] = (n/static_cast<float>(num_freq_samples))*(max_freq - min_freq) + min_freq;
    }
    return frequencies;
}

int main()
{
    // Defining the base signal
    const int duration {2};
    const int num_samples {10};
    const SignalType signal_type { SignalType::rect };
    // Defining where we will evaluate the F.T.
    const int num_freq_samples { 10 };
    const double min_freq { -2*M_PI };
    const double max_freq {  2*M_PI };	

    std::unique_ptr<const BaseSignal> f  { make_signal(signal_type, duration, num_samples) };
   
    // real_vector frequencies { make_frequencies(num_freq_samples, min_freq, max_freq) };  
    // complex_vector F { get_fourier_transform(frequencies, *f)  }; 

    // for (complex_double z : F)
    // {
    //     std::cout << z << std::endl;
    // }
    return 0;
}


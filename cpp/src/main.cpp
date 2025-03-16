//-> Make a new class SampledSignal, which encapsulates the signal values and where those signal values are evaluated.
//      -> Include many of the methods we had in BaseSignal before... get_times, get_sample_values, sample_rate etc.
// 	-> Create a function which takes in a BaseSignal derived class (Rect, SinWave), and returns a sampled signal.
// 	-> Now, fourier series and fourier transform (and their respective inverses) can all return sampled signal instances.
// 	-> except, that "where the signal values are evaluated at" is interpreted differently based on the context.
// Refactor the fourier series code to accommodate these changes.
// Write the code to compute the fourier transform...
// Write a function which computes the F.T. via the triangle trick.
// Compare F.T. to F.S. and plot, to make sure the code is working...

#include "sampled_signal.h"
#include "types.h"

#include <iostream>

int main()
{
    real_vector times {0, 1, 2, 3};
    complex_vector samples {complex_double(0,1), complex_double(1,0), complex_double(0,-1), complex_double(0,-1)}; 
    SampledSignal sampled_signal(times, samples);
    std::cout << sampled_signal.get_num_samples() << "\n";
    return 0;
}

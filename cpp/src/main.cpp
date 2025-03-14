// Refactor "BaseSignal"
// 	-> Now, represents almost the "continous" f(t), in the sense that you give it a value, and it will compute the sample
// 	value. 
// 		-> Make an interface for this.
// 		-> Make a single derived class to showcase
// 	-> Make a new class SampledSignal, which encapsulates the signal values and where those signal values are evaluated.
// 	-> Create a function which takes in a BaseSignal derived class (Rect, SinWave), and returns a sampled signal.
// 	-> Now, fourier series and fourier transform (and their respective inverses) can all return sampled signal instances.
// 	-> except, that "where the signal values are evaluated at" is interpreted differently based on the context.
// Refactor the fourier series code to accommodate these changes.
// Write the code to compute the fourier transform...
// Write a function which computes the F.T. via the triangle trick.
// Compare F.T. to F.S. and plot, to make sure the code is working...

#include "types.h"
#include "rect.h"

#include <iostream>

int main()
{
    double width { 1 };
    const Rect signal(width);
    std::cout << signal.compute_sample(0.75) << std::endl; 
    return 0;
}

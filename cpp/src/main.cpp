// -> Create a function which takes in a BaseSignal derived class (Rect, SinWave), and returns a sampled signal.  
// 	-> Now, fourier series and fourier transform (and their respective inverses) can all return
// sampled signal instances.  
// 	-> except, that "where the signal values are evaluated at" is interpreted differently based on the context.
// -> Refactor the fourier series code to accommodate these changes.  i
// -> Write the code to compute the fourier transform... 
// -> Write a function which computes the F.T. via the triangle trick.  
// -> Compare F.T. to F.S. and plot, to make sure the code is working...

#include "types.h"
#include "signal_factory.h"
#include "sampled_signal.h"
#include "base_signal.h"

#include <iostream>
#include <cmath>
#include <memory>

real_vector get_points(double min_point,
		       double max_point,
		       int num_points)
{
    real_vector points(num_points, 0);
    for (int n {0}; n < num_points; n++)
    {
        points[n] = min_point + (static_cast<double>(n) / num_points)*(max_point - min_point);
    }
    return points;
}

int main()
{
    using namespace std;
    // Domain points to sample at.
    double min_point { -2 };
    double max_point {  2 };
    int num_points { 10 };

    // Define what type of signal we want to sample.
    SignalType signal_type { SignalType::rect };
    double width { 1 };

    // Get the points in the domain we are sampling at.
    const real_vector points { get_points(min_point, max_point, num_points) };

    // Make the signal we wish to sample.
    std::unique_ptr<const BaseSignal> signal { make_signal(signal_type, width) }; 

    // Sample the signal
    std::unique_ptr<const SampledSignal> sampled_signal { sample_signal(points, std::move(signal)) };
	
    for (complex_double sample : sampled_signal->get_samples())
    {
        cout << sample << "\n";
    }
    return 0;
}

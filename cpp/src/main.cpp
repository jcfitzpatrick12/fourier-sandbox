// 	-> Now, fourier series and fourier transform (and their respective inverses) can all return
// sampled signal instances.  
// 	-> except, that "where the signal values are evaluated at" is interpreted differently based on the context.
// -> Refactor the fourier series code to accommodate these changes.  i
// -> Write the code to compute the fourier transform... 
// -> Write a function which computes the F.T. via the triangle trick.  
// -> Compare F.T. to F.S. and plot, to make sure the code is working...

#include "types.h"
#include "signal_factory.h"
#include "base_signal.h"
#include "sampled_signal.h"
#include "fourier.h"

#include <vector>
#include <iostream>
#include <memory>

real_vector get_points(double min_point,
		       double max_point,
		       int num_points)
{
    real_vector points(num_points, 0);
    for (int n {0}; n < num_points; n++)
    {
        points[n] = min_point + (static_cast<double>(n)/num_points) * (max_point - min_point);
    }
    return points;
}

int main()
{
    // Choose points in the domain to sample at.
    double min_point { -2 };
    double max_point {  2 };
    int num_points { 10 };
    real_vector points { get_points(min_point, max_point, num_points) };

    // Make a signal to sample.
    double width { 1 };
    std::unique_ptr<const BaseSignal> signal { make_signal(SignalType::rect, width) };

    // Sample the signal.
    SampledSignal sampled_signal { sample_signal(points, *signal) };   

    // Compute the fourier coefficients.
    int N { 10 };
    SampledSignal coeffs { get_fourier_coefficients(N, sampled_signal) }; 
    return 0;
}

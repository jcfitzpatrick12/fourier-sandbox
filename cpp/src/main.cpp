// -> Write the code to compute the fourier transform... 
// -> Compare with fourier coefficients (up to scale factor) for rect function.
// -> Write a function which computes the F.T. via the triangle trick.  
// -> Compare F.T. to F.S. and plot, to make sure the code is working...
// -> Perhaps even try wrap the C++ code !

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
    double min_time { -2 };
    double max_time {  2 };
    int num_times { 150 };
    real_vector times { get_points(min_time, max_time, num_times) };

    // Make a signal to sample.
    double width { 1 };
    std::unique_ptr<const BaseSignal> signal { make_signal(SignalType::rect, width) };

    // Sample the signal.
    SampledSignal f  { sample_signal(times, *signal) };   

    // Compute the fourier transform of the signal, at chosen frequencies.
    double min_frequency {-4 * M_PI};
    double max_frequency { 4 * M_PI};
    int num_frequencies { 10 };
    real_vector frequencies { get_points(min_frequency, max_frequency, num_frequencies) };

    SampledSignal F { get_fourier_transform(f, frequencies) }; 
   
    for (int k {0}; k < F.get_num_samples(); k++)
    {
        using namespace std;
	cout << F.get_sample(k)
	     << " at "
	     << F.get_point(k)
	     << " [Hz]"
	     << "\n";
    }
    return 0;
}

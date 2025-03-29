#include "sampled_signal.h"
#include "types.h"

SampledSignal get_fourier_coefficients(const int N,
 				       const SampledSignal& sampled_signal)
{
    complex_vector fourier_coefficients { complex_vector(N, complex_double(0,0)) };
    // Populate with physical frequencies associated with each harmonic.
    real_vector points { real_vector(N, 0) };
    return SampledSignal(points, fourier_coefficients);
}

#include <iostream>
#include <vector>
#include <cmath>

#include "types.h"
#include "constants.h"
#include "fourier.h"
#include "base_signal.h"

// Numerically integrates over the duration (trapezoidal rule in the case of constant sample rate).
complex_double trapz(const double delta_x,
                     const complex_vector& integrand)
{ 
    complex_double running_sum { 0.0 };

    for (complex_double f_x : integrand )
    {
        running_sum += f_x;
    }

    running_sum -= 0.5 * (integrand.front() + integrand.back());

    return (delta_x * running_sum);
}


// Computes the integrand corresponding to the n'th fourier coefficient for the signal.
const complex_vector get_fourier_integrand(const int n,
                                           const BaseSignal& signal)
{
    complex_vector fourier_integrand(signal.get_num_samples(), complex_double(0,0));

    complex_vector samples { signal.get_samples() };
    // Align with symbol convention in https://see.stanford.edu/Course/EE261
    complex_double i(0,1); 
    double T { signal.get_duration() }; 

    for (int k {0}; k < signal.get_num_samples(); ++k)
    {   
        complex_double t { signal.get_time(k) };
        complex_double exp_arg { - 2 * M_PI * i * static_cast<double>(n) * t / T };
        fourier_integrand[k] = (1/T) * samples[k] * std::exp(exp_arg);
    }

    return fourier_integrand;
}

// Computes the nth fourier coefficient (as defined in section 1.6.1 of https://see.stanford.edu/Course/EE261)
const complex_double get_fourier_coefficient(const int n,
                                             const BaseSignal& signal)
{
    complex_vector fourier_integrand { get_fourier_integrand(n, signal) };
    double delta_t = 1 / signal.get_sample_rate();
    return trapz(delta_t, fourier_integrand);
}


const complex_vector get_fourier_coefficients(const int N,
                                              const BaseSignal& signal)
{
    int num_coefficients { 2*N + 1 }; // + 1 to account for for the 0th term
    complex_vector coefficients(num_coefficients, complex_double(0.0));
    for (int m {0} ; m < (num_coefficients); ++m)
    {
        int n = -N + m;
        coefficients[m] = get_fourier_coefficient(n, signal);
    }
    return coefficients;
}


const complex_vector get_fourier_series(const int N,
                                        const BaseSignal& signal)
{

    complex_vector coefficients { get_fourier_coefficients(N, signal) };
    int num_coefficients { static_cast<int>(coefficients.size()) };

    int num_samples { signal.get_num_samples() };
    complex_double i(0,1); // Align with symbol convention in https://see.stanford.edu/Course/EE261
    double T { signal.get_duration() }; // Align with symbol convention in https://see.stanford.edu/Course/EE261

    complex_vector reconstructed_signal(num_samples, complex_double(0,0));

    // Iteratively reconstruct the sample at each time
    for (int k {0}; k < num_samples; ++k)
    {   
        complex_double t { signal.get_time(k) };
        complex_double running_sum(0,0);
        for (int m {0}; m < num_coefficients; ++m)
        {   
            int n = -N + m;
            complex_double exp_arg { 2 * M_PI * i * static_cast<double>(n) * t / T };
            running_sum += coefficients[m] * std::exp(exp_arg);
        }

        reconstructed_signal[k] = running_sum;
    }
    return reconstructed_signal;
}


// I'm integrating in the time domain, clearly!
// So this function is needs to be modified.
// const double get_delta_freq(const real_vector& frequencies)
// {
//     long unsigned int num_differences { frequencies.size() - 1 };
//     double delta_freq { frequencies[1] - frequencies[0] };
//     for (int n {0}; n<num_differences; n++)
//     {
//         if ((frequencies[n+1] - frequencies[n] - delta_freq) > EPSILON);
// 	{
//             throw std::logic_error("Expected equidistant samples in the frequency domain");
// 	}
//     }
//     return delta_freq;
// }


const complex_vector get_fourier_transform(const real_vector& frequencies,
					   const BaseSignal& signal)
{
    complex_vector F(frequencies.size(), complex_double(0,0));
    
    // The base signal is defined over some   
    // for (int n {0}; n < frequencies.size(); n++)
    // {
    //     int x; // Placeholder.
    //     // F[n] = trapz(delta_t, < extended signal samples in the time domain >)
    // }
    
    return F; 
}


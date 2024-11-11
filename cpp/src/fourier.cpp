#include <iostream>
#include <vector>
#include <cmath>

#include "types.h"
#include "fourier.h"
#include "base_periodic_signal.h"


// Numerically integrates over the period (trapezoidal rule in the case of constant sample rate).
complex_double trapz(const double delta_t,
                     const complex_vector& integrand)
{ 
    complex_double running_sum { 0.0 };

    for (complex_double f_x : integrand )
    {
        running_sum += f_x;
    }

    running_sum -= 0.5 * (integrand.front() + integrand.back());

    return (delta_t * running_sum);
}


// Computes the integrand corresponding to the nth fourier coefficient for the signal.
const complex_vector get_fourier_integrand(const int n,
                                           const BasePeriodicSignal& signal)
{
    complex_vector fourier_integrand(signal.get_num_samples(), complex_double(0,0));

    complex_vector samples { signal.get_samples() };
    complex_double i(0,1); // Align with symbol convention in https://see.stanford.edu/Course/EE261
    double T { signal.get_period() }; // Align with symbol convention in https://see.stanford.edu/Course/EE261

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
                                             const BasePeriodicSignal& signal)
{
    complex_vector fourier_integrand { get_fourier_integrand(n, signal) };
    double delta_t = 1 / signal.get_samp_rate();
    return trapz(delta_t, fourier_integrand);
}


const complex_vector get_fourier_coefficients(const int N,
                                              const BasePeriodicSignal& signal)
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
                                        const BasePeriodicSignal& signal)
{

    complex_vector coefficients { get_fourier_coefficients(N, signal) };
    int num_coefficients { static_cast<int>(coefficients.size()) };

    int num_samples { signal.get_num_samples() };
    complex_double i(0,1); // Align with symbol convention in https://see.stanford.edu/Course/EE261
    double T { signal.get_period() }; // Align with symbol convention in https://see.stanford.edu/Course/EE261

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


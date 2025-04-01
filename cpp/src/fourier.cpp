#include "sampled_signal.h"
#include "types.h"

#include <cmath>


complex_double integrate(const SampledSignal& integrand)
{
    complex_double running_sum(0,0); 
    for (int k {1}; k < integrand.get_num_samples(); k++)
    {
        running_sum += integrand.get_sample(k);
    }
    return integrand.get_sample_interval() * running_sum;
}


SampledSignal get_fourier_series_integrand(const int n,
		                           const SampledSignal& sampled_signal)
{
    // Initialise an array to hold the integrand sample values
    complex_vector integrand { complex_vector(sampled_signal.get_num_samples(), complex_double(0,0)) };
    
    complex_double i(0,1);
    double T { sampled_signal.get_range() };
    for (int k {0}; k < sampled_signal.get_num_samples(); k++)
    {
        double t { sampled_signal.get_point(k) };
	complex_double exp_arg { -2 * M_PI * i * static_cast<double>(n) * t / T };
        integrand[k] = (1/T) * sampled_signal.get_sample(k) * std::exp(exp_arg);	
    }

    // The integrand is itself a sampled signal, evaluated at the same domain points as
    // the signal which we are finding the fourier series coefficients.
    return SampledSignal(sampled_signal.get_points(), integrand);
}


complex_double get_fourier_coefficient(const int n,
				       const SampledSignal& sampled_signal)
{
    SampledSignal integrand { get_fourier_series_integrand(n, sampled_signal) };
    return integrate(integrand); 
}


SampledSignal get_fourier_coefficients(const SampledSignal& sampled_signal,
                                       const int N)
{
    // `+1` to account for the 0th term.
    int num_coefficients { 2*N + 1}; 
    
    // Initialise a vector to hold the coefficients.
    complex_vector coefficients { complex_vector(num_coefficients, complex_double(0,0)) };
   
    // Initialise a vector to hold the physical frequencies associated with each coefficient. 
    real_vector frequencies { real_vector(num_coefficients, 0) };

    // Keep track of the coefficient index in [-N, N]. That is, the k'th coefficient we
    // evaluate is c_{-N + k}, so that they are naturally ordered in terms of their
    // corresponding physical frequencies. 
    int n { -N };
    
    double T { sampled_signal.get_range() };
    
    // Compute the coefficient, and then assign it a physical frequency
    // based on it's corresponding harmonic in the series. 
    for (int k {0}; k < num_coefficients; k++)
    {
	coefficients[k] = get_fourier_coefficient(n, sampled_signal); 
	frequencies [k] = n / T;
        n++;	
    }
    
    return SampledSignal(frequencies, coefficients);
}


SampledSignal get_fourier_series(const SampledSignal& sampled_signal,
                                 const int N)
{
    SampledSignal coeffs { get_fourier_coefficients(sampled_signal, N) };
    
    // Initialise a vector to hold the partial sums.
    complex_vector partial_sums { complex_vector(sampled_signal.get_num_samples(), complex_double(0, 0)) };
   
    double T { sampled_signal.get_range() };
    complex_double i(0, 1);

    // Compute the partial sum for each point in the domain.
    for (int m {0}; m < partial_sums.size(); m++)
    {
	// Evaluate the partial sum at the same times as the input signal.
	double t { sampled_signal.get_point(m) };             

        // Compute the partial sum. 
	complex_double running_sum(0,0);
	for (int k {0}; k < coeffs.get_num_samples(); k++)
        {
	    complex_double exp_arg { 2 * M_PI * i * coeffs.get_point(k) * t };
            running_sum += coeffs.get_sample(k) * std::exp(exp_arg); 
	}
        partial_sums[m] = running_sum; 
    }
    // The partial sum has been evaluated at the same times as the input signal. 
    return SampledSignal(sampled_signal.get_points(), partial_sums);
}



// Write the fourier series representation to file and plot using Python.
// Compare the fourier series representation to the original on the same graph.

#include <iostream>

#include "sin_wave.h"
#include "fourier.h"
#include "simple_io.h"

int main()
{
    double period { 1.0 }; // Period of the signal [s]
    int num_samples { 100 }; // Number of samples to take over the period
    int N { 10 }; // Coefficients are evaluated for n in [-N, N] inclusive 

    SinWave sin_wave(period, num_samples);
    complex_vector original_samples { sin_wave.get_samples() };
    complex_vector reconstructed_samples { get_fourier_series(N, sin_wave) };
    
    write_to_file(reconstructed_samples);
    return 0;
}
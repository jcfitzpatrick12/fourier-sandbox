#ifndef FOURIER_H
#define FOURIER_H

#include "base_periodic_signal.h"

// Computes all the fourier coefficients for all n in [-N, N] inclusive.
const complex_vector get_fourier_coefficients(const int N,
                                              const BasePeriodicSignal& signal);


// Reconstructs the input signal as a fourier series.
// Computes the partial sums using fourier coefficients for all n in [-N, N] inclusive.
const complex_vector get_fourier_series(const int N,
                                        const BasePeriodicSignal& signal);

#endif

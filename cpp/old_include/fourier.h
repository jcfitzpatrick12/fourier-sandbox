#ifndef FOURIER_H
#define FOURIER_H

#include "base_signal.h"
#include "types.h"

// Computes all the fourier coefficients for all n in [-N, N] inclusive.
const complex_vector get_fourier_coefficients(const int N,
                                              const BaseSignal& signal);


// Reconstructs the input signal as a fourier series.
// Computes the partial sums using fourier coefficients for all n in [-N, N] inclusive.
const complex_vector get_fourier_series(const int N,
                                        const BaseSignal& signal);


// Evaluate the fourier transform at each of the input frequencies.
const complex_vector get_fourier_transform(const real_vector& frequencies,
					   const BaseSignal& signal);

#endif

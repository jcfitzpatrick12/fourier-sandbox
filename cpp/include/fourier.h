#ifndef FOURIER_H
#define FOURIER_H

#include "sampled_signal.h"
#include "types.h"

// Computes the Fourier coefficients, c_{n}, for all n in [-N, N], according to the formula:
// 
//     c_{n} = \frac{1}{T} \int_{t_{0}}^{t_{M}} f(t) \, e^{-2 \pi i \frac{n}{T} t} \, dt
//
// which we approximate numerically using the sum:
// 
//     c_{n} \approx \Delta t \sum_{m=1}^{M} f(t_{m}) \, e^{-2 \pi i \frac{n}{T} t_{m}}
//
// where:
//     - f(t) is the input signal, evaluated at time t.
//     - M is the total number of samples taken over the period.
//     - \Delta t is the sampling interval.
//     - t_{m} is the time corresponding to the m'th sample.
//     - T = t_{M} - t_{0} is the total period (discarding the assumed small interval
//       between the "end" of the sampled interval, and the "start" of the next period)
SampledSignal get_fourier_coefficients(const int N,
 		                       const SampledSignal& sampled_signal);

// Compute the fourier series representation of the input signal using the partial
// sum:  
//
//     f[m] = \sum_{n=-N}^{N} \, c_{n} \, e^{2 \pi i \frac{n}{T} t_{m}}
//
// where:
//     - N is a positive integer indicating the number of terms to use in the 
//       partial sum.
//     - c_{n} is the n'th fourier coefficient.
//     - t_{m} is the time corresponding to the m'th sample of the input signal. 
//     - T = t_{M} - t_{0} is the total period (discarding the assumed small interval
//       between the "end" of the sampled interval, and the "start" of the next period)
SampledSignal get_fourier_series(const int N,
		                 const SampledSignal& sampled_signal);


#endif

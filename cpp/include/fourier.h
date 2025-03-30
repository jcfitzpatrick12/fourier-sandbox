#ifndef FOURIER_H
#define FOURIER_H

#include "sampled_signal.h"
#include "types.h"

// Computes the Fourier coefficients, c_{n}, for all n in [-N, N], according to the formula:
// 
//     c_{n} = \frac{1}{T} \int_{T_{a}}^{T_{b}} f(t) \, e^{-2 \pi i \frac{n}{T} t} \, dt
//
// which we approximate numerically using the sum:
// 
//     c_{n} \approx \Delta t \sum_{m=1}^{M} f(t_{m}) \, e^{-2 \pi i \frac{n}{T} t_{m}}
//
// where:
//     - M is the total number of samples taken over the period.
//     - \Delta t is the sampling interval.
//     - t_{m} is the time corresponding to the m'th sample.
//     - T_{a} = t_{0} is the start of the sampled interval.
//     - T_{b} = t_{M} is the end of the sampled interval.
//     - T = T_{b} - T_{a} is the total period.
SampledSignal get_fourier_coefficients(const int N,
 		                       const SampledSignal& sampled_signal);

#endif

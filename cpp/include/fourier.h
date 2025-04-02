#ifndef FOURIER_H
#define FOURIER_H

#include "sampled_signal.h"
#include "types.h"

// Computes the Fourier coefficients, c_{n}, for all n in [-N, N], according to the formula
// 
//     c_{n} = \frac{1}{T} \int_{\text{period}} dt \left( f(t) e^{-2 \pi i \frac{n}{T} t} \right)
//
// where the integral is assumed over one period of the signal, and
//
//     - f is the input signal
//     - t is the time
//     - T is the period
//     - i is the imaginary unit
//
// We approximate this numerically using a right hand Riemann sum
// 
//     c_{n} \approx \frac{1}{T} \Delta t \sum_{m=1}^{M} f(t_{m}) e^{-2 \pi i \frac{n}{T} t_{m}}
//
// where:
//
//     - \Delta t is the sampling interval
//     - f is the input signal
//     - M is the total number of samples taken over the period.
//     - t_{m} is the time corresponding to the m'th sample.
//     - i is the imaginary unit
//     - T = t_{M} - t_{0} is the total period (discarding the assumed small interval
//       between the "end" of the sampled interval, and the "start" of the next period)
//       
SampledSignal get_fourier_coefficients(const SampledSignal& sampled_signal,
                                       const int N);

// Compute the Fourier series representation of the input signal according to the formula:   
//
//     f(t) = \sum_{-\infty}^{\infty} \, c_{n} e^{2 \pi i \frac{n}{T} t}
//
// where
//
//     - t is the time 
//     - T is the period of the input signal
//     - c_{n} is the n'th fourier coefficient
//     - i is the imaginary unit
//
// which we approximate using the partial sum   
//
//     f(t_{m}) \approx \sum_{n=-N}^{N} \, c_{n} \, e^{2 \pi i \frac{n}{T} t_{m}}
//
// where:
//
//     - t_{m} is the time corresponding to the m'th sample of the input signal. 
//     - f(t_{m}) is the partial sum evaluated at t_{m}
//     - N is a positive integer indicating the number of terms to use in the 
//       partial sum.
//     - c_{n} is the n'th fourier coefficient.
//     - T = t_{M} - t_{0} is the total period (discarding the assumed small interval
//       between the "end" of the sampled interval, and the "start" of the next period)
//
SampledSignal get_fourier_series(const SampledSignal& sampled_signal,
                                 const int N);


// Compute the fourier transform of the input signal, using the formula:
//
//    F(\nu) = \int_{-\infty}^{\infty} dt \left( f(t) e^{-2 \pi i \nu t } \right)
//
// where
//
//     - f is the input signal
//     - F is the fourier transform of f
//     - t represents time
//     - \nu represents frequency
//     - i is the imaginary unit.
//
// which we approximate using the right hand Riemann sum
//
//    F(\nu_{n}) \approx \Delta t \sum_{m=1}^{M} f(t_{m}) e^{-2 \pi i \nu_{n} t_{m}}
//
// where 
// 
//    - f is the input signal
//    - F is the fourier transform of f
//    - t_{m} is the m'th sample in the input signal
//    - \nu_{n} is the n'th frequency we are evaluating the transform at    
//    - i is the imaginary unit 
// 
// This is only a good approximation if f(t) decays sufficiently for large |t|
SampledSignal get_fourier_transform(const SampledSignal& sampled_signal,
                                    const real_vector frequencies);

#endif

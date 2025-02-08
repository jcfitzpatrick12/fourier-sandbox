#ifndef SIN_WAVE_H
#define SIN_WAVE_H

#include "base_periodic_signal.h"
#include "types.h"

class SinWave : public BasePeriodicSignal
{
public:
    SinWave(const double period,
            const int num_samples);
    ~SinWave();
    const complex_vector compute_samples() const override;
};

#endif

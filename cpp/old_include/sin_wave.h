#ifndef SIN_WAVE_H
#define SIN_WAVE_H

#include "types.h"
#include "base_signal.h"

class SinWave : public BaseSignal
{
public:
    SinWave(const double duration,
            const int num_samples);
    ~SinWave();
    void compute_samples()  override;
};

#endif

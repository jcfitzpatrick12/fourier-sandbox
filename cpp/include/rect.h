#ifndef RECT_H
#define RECT_H

#include "base_signal.h"
#include "types.h"

class Rect : public BaseSignal
{
public:
    Rect(double width);
    ~Rect();
    complex_double compute_sample(double point) const override; 
private:
    double width_;
};


#endif

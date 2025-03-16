#include "rect.h"

#include <cmath>

Rect::Rect(double width)
     : BaseSignal(),
       width_(width)
{}

Rect::~Rect()
{}

complex_double Rect::compute_sample(double point) const
{
    if ( fabs(point) < width_/2 )
    {
        return complex_double(1,0);
    }
    return complex_double(0,0);
}

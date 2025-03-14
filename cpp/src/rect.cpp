#include "rect.h"
#include "base_signal.h"
#include "types.h"

#include <cmath>

Rect::Rect(double width) 
     : BaseSignal(), 
       width_(width)
{}

Rect::~Rect() 
{}

complex_double Rect::compute_sample(double point) const
{
    if ( fabs(point) <= width_/2) 
    {
        return 1;
    }
    return 0;
}

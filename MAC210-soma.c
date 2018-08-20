#include "float.h"

float soma (float x, float y) {
    if (isnan(x) || isnan(y)
        return NAN;
    
    if (x == 0.0f)
        return y;
    
    if (y == 0.0f)
        return x;
    
    if (!isfinite(x))
        return (y == -x) ? NAN : x;
        
    if (!isfinite(y))
        return y;
}
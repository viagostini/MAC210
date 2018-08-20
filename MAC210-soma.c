#include "float.h"

float soma2 (int ex, int64_t mx, int ey, int64_t my) {
    if (ex > ey)
        return soma2(ey, my, ex, mx);   // troca

    // agora ex <= ey
    if (ey < EXP_MIN)
        return 0;
    
    if (ex > EXP_MAX)
        return INFINITY;

    int de = ey - ex;

    if (de >= 25)
        return ldexp(my, ey);

    // de < 25
    int64_t m = (my << de) + mx;

    int c = clz(m)      // clz = numero de 0 a esquerda na repr binária
    int r = 64-24-c
    int64_t mf = m >> r;
    int64_t resto = m - (mf << r);

    if (resto < (1 << (r-1)))
        return ldexp(mf, ex);
    else
        return ldexp(mf+1, ex);


}

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

    int exp_x;
    int exp_y;

    float xn = frexp(x, &exp_x);    // 1/2 <= xn <= 1 e x = 2^(exp_x) * xn
    float yn = frexp(y, &exp,y);

    int64_t ix = ldexp(xn, 24);       // 2^23 <= |ix| <= 2^24 (inteiro)
    int64_t iy = ldexp(yn, 24);

    exp_x -= 24;
    exp_y -= 24;

    // agora x = 2^(exp_x) * ix,   y = 2^(exp_y) * iy
    // ix e iy inteiros de 24 bits

    if (ix < 0)
        if (iy < 0)
            return -soma2(exp_x, -ix, exp_y, -iy);
        else
            return sub(exp_y, iy, exp_x, -ix);
    else
        if (iy < 0)
            return sub(exp_x, ix, -iy, exp_iy);
        else
            return soma2(exp_x, ix, exp_y, iy);
}
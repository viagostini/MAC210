int inter(float *x, float *y,
            float a1, float b1, float c1,
            float a2, float b2, float c2) {
   
    if (fabs(a1) < fabs(a2))
        return inter(x, y, a2, b2, c2, a1, b1, c1);
    
    if (a1 == 0)
        return -1;
        
    if (fabs(a1) < fabs(b1))
        return inter(y, x, b1, a1, c1, b2, a2, c2);
                            
    if (fabs(a1) < fabs(b2))
        return inter(y, x, b2, a2, c2, b1, a1, c1);
                            
    float q = a2/a1;
    float b3 = b2 - q*b1;
    float c3 = c2 - q*c1;
    
    *y = c3/b3;
    *x = (c1 - b1*(*y))/a1;
    
    return 1;
}



Obs: entre 2^e e 2^(e+1), o intervalo entre os numeros é igual e é dado por 2^e * eps
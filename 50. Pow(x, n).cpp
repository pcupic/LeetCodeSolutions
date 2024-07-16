double myPow(double base, int exponent) {
    
    if(exponent == 0) return 1;
    long long exp = exponent;
    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }

    double output = 1;
    double multiplier = base;

    while (exp > 0) {
        if (exp % 2 == 1) {
            output *= multiplier;
        }
        multiplier *= multiplier;
        exp /= 2;
    }

    return output;
}

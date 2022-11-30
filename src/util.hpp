#include <NTL/ZZ.h>

// solve a * x + b * y = gcd, given a and b
NTL::ZZ extended_gcd(NTL::ZZ a, NTL::ZZ b, NTL::ZZ &x, NTL::ZZ &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }

    NTL::ZZ x1, y1;
    NTL::ZZ gcd = extended_gcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
 
    return gcd;
}

NTL::ZZ gcd(NTL::ZZ a, NTL::ZZ b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

NTL::ZZ modpow(NTL::ZZ base, NTL::ZZ exp, NTL::ZZ mod) {
    NTL::ZZ res = NTL::ZZ(1);
    for (; exp != 0; exp >>= 1) {
        if (exp % 2 == 1) res = res * base % mod;
        base = base * base % mod;
    }
    return res;
}

NTL::ZZ modinverse(NTL::ZZ a, NTL::ZZ b) {
    NTL::ZZ x, y;
    NTL::ZZ g = extended_gcd(a, b, x, y);
    assert(g == 1);
    return ((x % b + b) % b);
}

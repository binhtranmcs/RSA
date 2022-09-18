#include <NTL/ZZ.h>

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
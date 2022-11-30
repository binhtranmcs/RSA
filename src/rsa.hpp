#include "prime_generator.hpp"

class RSA {
    NTL::ZZ n, d, e;
    PrimeGenerator *generator;
public:
    RSA(int bits) {
        generator = new PrimeGenerator();
        NTL::ZZ p = generator->get_prime(bits);
        NTL::ZZ q = generator->get_prime(bits);
        n = p * q;
        NTL::ZZ totient = (p - 1) * (q - 1);
        calculate_keys(totient);
    }

    RSA(NTL::ZZ p, NTL::ZZ q) {
        n = p * q;
        NTL::ZZ totient = (p - 1) * (q - 1);
        calculate_keys(totient);
    }

    NTL::ZZ get_e() { return e; }
    NTL::ZZ get_d() { return d; }

    NTL::ZZ encrypt(NTL::ZZ p) {
        return modpow(p, e, n);
    }

    NTL::ZZ decrypt(NTL::ZZ c) {
        return modpow(c, d, n);
    }

private:
    void calculate_keys(NTL::ZZ totient) {
        do {
            e = RandomBnd(totient);
        } while (gcd(e, totient) != 1);
        d = modinverse(e, totient);
    }
};
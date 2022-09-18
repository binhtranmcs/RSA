#include <vector>
#include <NTL/ZZ.h>

#include "util.hpp"

class PrimeGenerator {
    std::vector<int> small_primes;
public:
    PrimeGenerator() {
        for (int val = 2; val < 1000; ++val) {
            bool is_prime = true;
            for (int i = 2; i * i <= val; ++i) {
                if (val % i == 0) {
                    is_prime = false;
                    break;
                }
            } 
            if (is_prime) small_primes.push_back(val);
        }
    }

    bool is_prime(NTL::ZZ num) {
        for (const int &prime : small_primes) {
            if (num == prime) return true;
            if (num % prime == 0) return false;
        }

        for (int i = 0; i < 100; ++i) {
            if (!miller_rabin(num)) return false;
        }
        return true;
    }

    NTL::ZZ get_prime(int bits) {
        NTL::ZZ MAX = NTL::power(NTL::ZZ(2), bits);
        NTL::ZZ MIN = NTL::power(NTL::ZZ(2), bits - 1);
        while (true) {
            NTL::ZZ num = RandomBnd(MAX);
            if (num < MIN) continue;
            if (is_prime(num)) return num;
        }
        return NTL::ZZ(-1);
    }

private:
    bool miller_rabin(NTL::ZZ num) {
        NTL::ZZ a = RandomBnd(num);
        NTL::ZZ d = num - 1, s = NTL::ZZ(0);
        while (d % 2 == 0) {
            d /= 2;
            s++;
        }
        NTL::ZZ val = modpow(a, d, num);
        if (val == 1 || val == num - 1) return true;
        for (int i = 1; i < s; ++i) {
            val = val * val % num;
            if (val == num - 1) return true;
        }
        return false;
    }
};
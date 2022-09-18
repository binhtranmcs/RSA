#include <cassert>
#include <NTL/ZZ.h>

#include "prime_generator.hpp"

int main() {
    const int BITS = 1000;
    PrimeGenerator *generator = new PrimeGenerator();
    NTL::ZZ p = generator->get_prime(BITS);
    NTL::ZZ q = generator->get_prime(BITS);

    std::cout << p << '\n' << q << '\n';
    NTL::ZZ tot = (p - 1) * (q - 1);
    
    NTL::ZZ e;
    do {
        e = RandomBnd(tot);
    } while (gcd(e, tot) != 1);
    std::cout << e << '\n';

    NTL::ZZ d = modinverse(e, tot);
    std::cout << d << '\n';
    assert(d * e % tot == 1);
}
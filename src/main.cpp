#include <cassert>
#include <NTL/ZZ.h>

#include "prime_generator.hpp"

int main() {
    int bits; std::cin >> bits;
    PrimeGenerator *generator = new PrimeGenerator();
    NTL::ZZ p = generator->get_prime(bits);
    NTL::ZZ q = generator->get_prime(bits);

    std::cout << "first prime:  " << p << '\n';
    std::cout << "second prime: " << q << '\n';
    NTL::ZZ tot = (p - 1) * (q - 1);
    
    NTL::ZZ e;
    do {
        e = RandomBnd(tot);
    } while (gcd(e, tot) != 1);
    std::cout << "public key:  " << e << '\n';

    NTL::ZZ d = modinverse(e, tot);
    std::cout << "private key: " << d << '\n';
    assert(d * e % tot == 1);
}
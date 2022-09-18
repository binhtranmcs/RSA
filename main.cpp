#include <NTL/ZZ.h>
#include "prime_generator.hpp"

using namespace std;

int main() {
    PrimeGenerator gen = PrimeGenerator();
    cout << gen.get_prime(500) << '\n';
}
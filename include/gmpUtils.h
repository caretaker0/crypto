#ifndef _GMPUTILS_H
#define _GMPUTILS_H
#include <gmp.h>

void gmpUtils_getRandomPrime(mpz_t rand_num, int rand_bit);
void gmpUtils_carmichaelTotient(mpz_t euler_totient, mpz_t p, mpz_t q);
int gmpUtils_coprimeNumber(mpz_t a, mpz_t b);

#endif

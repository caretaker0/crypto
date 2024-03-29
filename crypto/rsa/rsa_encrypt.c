#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>

void rsa_encrypt(mpz_t* C, mpz_t M, PUBLIC_KEY* public_key){
	
	mpz_powm(*C, M, public_key->exponent, public_key->modulus);
}

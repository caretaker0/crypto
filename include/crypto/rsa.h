#ifndef _RSA_H
#define _RSA_H

typedef struct PUBLIC_KEY{
	mpz_t modulus;
	mpz_t exponent;
}PUBLIC_KEY;

typedef struct PRIVATE_KEY{
	mpz_t modulus;
	mpz_t exponent;
}PRIVATE_KEY;

void rsa_keyGen(struct PUBLIC_KEY* public_key, struct PRIVATE_KEY* private_key, int size);
void rsa_encrypt(mpz_t* C, mpz_t M, PUBLIC_KEY* public_key);
void rsa_decrypt(mpz_t* M, mpz_t C, PRIVATE_KEY* private_key);

#endif

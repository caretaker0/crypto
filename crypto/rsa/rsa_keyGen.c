#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>



void rsa_keyGen(PUBLIC_KEY* public_key, PRIVATE_KEY* private_key, int size){

	mpz_t e;		mpz_init_set_str(e, "65537", 10);
	mpz_t p, pMinusOne;	mpz_init(p); mpz_init(pMinusOne);
	mpz_t q, qMinusOne;	mpz_init(q); mpz_init(qMinusOne);
	mpz_t d;		mpz_init(d);
	mpz_t n;		mpz_init(n);
	mpz_t lambdaN;		mpz_init(lambdaN);
	mpz_t gcdEP;		mpz_init(gcdEP);
	mpz_t gcdEQ;		mpz_init(gcdEQ);

	/* compute random first value of p and q */
	gmpUtils_getRandomPrime(p, size/2);
	gmpUtils_getRandomPrime(q, size/2);
	
	mpz_sub_ui(pMinusOne, p, 1);
	mpz_sub_ui(qMinusOne, q, 1);

	mpz_mul(n, p, q);

	while(mpz_sizeinbase(n , 2) != size){
		gmpUtils_getRandomPrime(p, size/2);
		gmpUtils_getRandomPrime(q, size/2);

		mpz_sub_ui(pMinusOne, p, 1);
		mpz_sub_ui(qMinusOne, q, 1);
		mpz_gcd(gcdEP, e, pMinusOne);
		mpz_gcd(gcdEQ, e, qMinusOne);

		mpz_mul(n, p, q);

		if((mpz_cmp_ui(gcdEP, 1) != 0) || (mpz_cmp_ui(gcdEQ, 1) != 0)){
			continue;
		}
	}

	mpz_mul(n, p, q);
	gmpUtils_carmichaelTotient(lambdaN, p, q);
	
	/* 
	 * Here we compute the private exponent d with the mpz_invert function, 
	 * that is d is the modular multiplicative inverse of e mod lambdaN.
	 */
	
	mpz_invert(d, e, lambdaN);
	
	/* push computed value into keys struct public_key and private_key */
	mpz_init_set(public_key->modulus, n);
	mpz_init_set(public_key->exponent, e);
	mpz_init_set(private_key->modulus, n);
	mpz_init_set(private_key->exponent, d);
	
	/* Debug *//*
	gmp_printf("p      = %Zd\n", p);
	gmp_printf("q      = %Zd\n", q);
	gmp_printf("n      = %Zd\n", n);
	gmp_printf("lambda(n) = %Zd\n", lambdaN);
	gmp_printf("e      = %Zd\n", e);
	gmp_printf("d      = %Zd\n", d);
	*/
}


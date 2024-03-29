#include <stdio.h>
#include <gmp.h>
#include <gmpUtils.h>

#include <rsa.h>

int  main(void){
	
	PUBLIC_KEY public_key;
	PRIVATE_KEY private_key;
	
	mpz_t M; mpz_init_set_str(M, "426f6e6a6f7572204d616d616e", 16);
	mpz_t C; mpz_init(C);

	int key_size = 128;

	rsa_keyGen(&public_key, &private_key, key_size);

	rsa_encrypt(&C, M, &public_key);
	gmp_printf("C = %Zx\n", C);
	
	rsa_decrypt(&M, C, &private_key);
	gmp_printf("M = %Zx\n", M);

	return 0;
}

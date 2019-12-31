CC = gcc
CFLAGS = -Wall -lgmp
NAME = main

# Include flags
INCLUDE_CRYPTO_FLAG = -I./include/crypto
INCLUDE_FLAG = -I./include

# Directories
GMPUTILS_DIR = lib/gmpUtils
RSA_DIR = crypto/rsa


all: main clean

# Construct main binary

main: main.o rsa_keyGen.o gmpUtils_getRandomPrime.o gmpUtils_eulerTotient.o gmpUtils_coprimeNumber.o gmpUtils_gcd.o
	$(CC) $(CFLAGS) -o main main.o rsa_keyGen.o gmpUtils_getRandomPrime.o gmpUtils_eulerTotient.o gmpUtils_coprimeNumber.o gmpUtils_gcd.o

main.o: src/main.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) $(INCLUDE_CRYPTO_FLAG) -o main.o -c src/main.c 


# Compile rsa files

rsa_keyGen.o: $(RSA_DIR)/rsa_keyGen.c 
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) $(INCLUDE_CRYPTO_FLAG) -o rsa_keyGen.o -c $(RSA_DIR)/rsa_keyGen.c


# Compile gmpUtils library

gmpUtils_getRandomPrime.o: $(GMPUTILS_DIR)/gmpUtils_getRandomPrime.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -o gmpUtils_getRandomPrime.o -c $(GMPUTILS_DIR)/gmpUtils_getRandomPrime.c

gmpUtils_eulerTotient.o: $(GMPUTILS_DIR)/gmpUtils_eulerTotient.c 
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -o gmpUtils_eulerTotient.o -c $(GMPUTILS_DIR)/gmpUtils_eulerTotient.c

gmpUtils_coprimeNumber.o: $(GMPUTILS_DIR)/gmpUtils_coprimeNumber.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -o gmpUtils_coprimeNumber.o -c $(GMPUTILS_DIR)/gmpUtils_coprimeNumber.c

gmpUtils_gcd.o: $(GMPUTILS_DIR)/gmpUtils_gcd.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -o gmpUtils_gcd.o -c $(GMPUTILS_DIR)/gmpUtils_gcd.c

clean:
	rm -rf *.o
mrproper: clean
	rm -rf main

#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256


//Method prints big numbers.
void printBN(char *msg, BIGNUM *a)
{
	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

//Initialise the variables.
int main ()
{

BN_CTX *ctx = BN_CTX_new();
BIGNUM *m = BN_new();
BIGNUM *n = BN_new();
BIGNUM *res = BN_new(); //res = result.
BIGNUM *d = BN_new();


// Initialize n, m, d

BN_hex2bn(&m, "49206f776520796f752024323030302e"); // Task4 Message in HEX.

BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5"); //Public Key.

BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D"); //Private key.

// Signing the message using m**d mod n.
BN_mod_exp(res, m, d, n, ctx);
printBN("Generated Signature = ", res);



return 0;

}

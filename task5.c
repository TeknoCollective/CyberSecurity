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
BIGNUM *s= BN_new();


// Initialize n, m, d

BN_hex2bn(&m, "4C61756e63682061206d697373696C652E"); // Task5 Message in HEX.

BN_hex2bn(&s, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");//Signature EDIT.

BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115"); //Public Key.


BN_hex2bn(&d, "010001"); //Private key.

printBN("Message = ", m);//Print out original message.

// Signing the message using s**d mod n.
BN_mod_exp(res, s, d, n, ctx);
printBN("Calculated Signature = ", res); //Print out result.


//Create a loop to check if the signatures are valid.
if (BN_cmp(res, m)==0)

	printf("RESULT: Valid Signature.");

else 

	printf("RESULT: Invalid Signature.");

return 0;

}

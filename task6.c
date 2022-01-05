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



BN_hex2bn(&m, "1a32f255c6722d51956eacd6dad8eab3b5c236af7c6eb67508052ceef77a847a"); // Task6 Message in HEX.



BN_hex2bn(&s, "b4e27b22fcf4a1d34c8a2fe6e0f423c0ad1b5834fb2f85311ecfd0f0803c9493a137ba834eaf61cebe9ced799781f7a7b80638a1ce219e8f26209e7b236feaa68324c1bceedd4f63fc30464c31040492f73b9762f752ff7c409fd456b3549b0bffb58a843a08c5a08d67a164b168455eb9e28bd436975b1a3b9cbc34d136c663a4b7031c91990acc74067ceacae9751ec5ad13eb3de5c160dae6ff1db5e90bf70228636d508a9e0bd1137a16b5ab25a2efa398eb4ef5db5d15ae893083ad2dde5be08213d40fe16f7be3e0ade67dc40928227b7e1956e6fa1d00d1727bd86a4d35ac4c141bcb6fed294c982e57c40a47c178cc17419543332be45ea26fcf851d");//Signature EDIT.



BN_hex2bn(&n, "D018CF45D48BCDD39CE440EF7EB4DD69211BC9CF3C8E4C75B90F3119843D9E3C29EF500D10936F0580809F2AA0BD124B02E13D9F581624FE309F0B747755931D4BF74DE1928210F651AC0CC3B222940F346B981049E70B9D8339DD20C61C2DEFD1186165E7238320A82312FFD2247FD42FE7446A5B4DD75066B0AF9E426305FBE01CC46361AF9F6A33FF6297BD48D9D37C1467DC75DC2E69E8F86D7869D0B71005B8F131C23B24FD1A3374F823E0EC6B198A16C6E3CDA4CD0BDBB3A4596038883BAD1DB9C68CA7531BFCBCD9A4ABBCDD3C61D7931598EE81BD8FE264472040064ED7AC97E8B9C05912A1492523E4ED70342CA5B4637CF9A33D83D1CD6D24AC07"); //Public Key.





BN_hex2bn(&d, "10001"); //Private key.



printBN("Message = ", m);//Print out original message.



// Signing the message using s**d mod n.

BN_mod_exp(res, s, d, n, ctx);

printBN("Calculated Signature = ", res); //Print out result.



return 0;



}
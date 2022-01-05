
#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM *a)
{
   /*Use BN_bn2hex(a) for hex string
    *Use BN_bn2dec(a) for decimal string*/
char *number_str = BN_bn2hex(a);
printf("%s %s\n", msg, number_str);
OPENSSL_free(number_str);
}

int main ()
{
BN_CTX *ctx = BN_CTX_new();
BIGNUM *p = BN_new();
BIGNUM *a = BN_new();
BIGNUM *q = BN_new();
BIGNUM *e = BN_new();
BIGNUM *res = BN_new();
BIGNUM *b = BN_new();
BIGNUM *t1 = BN_new();
BIGNUM *t2 = BN_new();
BIGNUM *t3 = BN_new();


// Initialize a, b, n
//BN_generate_prime_ex(a, NBITS, 1, NULL, NULL, NULL);
BN_dec2bn(&b, "1");
BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
BN_hex2bn(&e, "0D88C3");
BN_sub(t1,p,b);
BN_sub(t2,q,b);



BN_mul(t3, t1, t2, ctx);

BN_mod_inverse(res, e, t3, ctx);
printBN("d = ", res); //print the private key d.


return 0;
}
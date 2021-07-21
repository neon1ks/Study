#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

typedef unsigned long long fibo_type;
#define FIBO_FORMAT "%10llu"

void printFibo(fibo_type num)
{
    printf(FIBO_FORMAT, num);
}

int test1()
{
    int num = -1;
    fibo_type a = 0, b = 1, c;

    printf("%4d: ", ++num);
    printFibo(a);
    printf("\n");

    printf("%4d: ", ++num);
    printFibo(b);
    printf(" (");
    printf("%llu", b % 5);
    printf(")\n");

    c = a + b;
    while (c >= b) {
        printf("%4d: ", ++num);
        printFibo(c);
        printf(" (");
        printf("%llu", c % 5);
        printf(")\n");
        a = b;
        b = c;
        c = a + b;
    }
    printf("Остановка после %d знаков\n", num);
    printFibo(c);
    printf("\n");
    return 0;
}

int test2()
{
    int num = 0;
    mpz_t f_1;
    mpz_t f_2;

    mpz_init(f_1);
    mpz_init(f_2);
    mpz_set_ui(f_1, 0);
    mpz_set_ui(f_1, 1);
    printf("%10d: 0\n", ++num);

    while (1) {
        mpz_add(f_1, f_2, f_1);
        mpz_swap(f_1, f_2);
        char *res = mpz_get_str(NULL, 10, f_2);
        printf("%10d: %s\n", ++num, res);
        free(res);
    }

    mpz_clear(f_1);
    mpz_clear(f_2);
    return 0;
}

int main()
{
    return test1();
}

#include <stdio.h>
#include <math.h>
#include <limits.h>

int counter = 0;
int errors = 0;

unsigned long int MAX(unsigned long int n, unsigned long int m) {return (n > m) ? n : m;}

unsigned long int func(unsigned long int n, unsigned long int m){
    unsigned long int a, b;
    counter += 1;
    if (counter == 10000 || n == 1 || m == 1 || (n % 2 == 0 && m % 2 == 0)){
        errors = -1;
        return 0;
    }
    if (m > ULONG_MAX/n){
        errors = -2;
        return 0;
    }
    if (((n * m) % 2 != 0)){
        return MAX(n+m, n*m);
    }
    else{
        a = func(n*m/2, m);
        b = func(n, n*m/2);
        if (a > ULONG_MAX-b){
            errors = -2;
            return 0;
        }
        return a+b;
    }
}


int main(){
    unsigned long int n, m;
    unsigned long int total;
    scanf("%ld %ld", &n, &m);
    total = func(n, m);
    if (errors == -1) printf("endless\n");
    else if (errors == -2) printf("overflow\n");
    else printf("%ld\n", total);
    return 0;
}

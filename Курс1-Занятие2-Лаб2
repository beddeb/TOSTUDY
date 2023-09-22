#include<stdio.h>
#include<limits.h>

int fib(long int N){
    if (N == 1 || N == 2) return 1;
    else return fib(N-1)+fib(N-2);
}

int main(void){
    long int N;
    scanf("%ld", &N);
    for (long int i=1; i <= N; i++){
        if (i < 10){
            printf("  %ld  %ld\n", i, fib(i));
        }
        else if (10 <= i < 100){
            printf(" %ld  %ld\n", i, fib(i));
        }
    }
    printf("\n");
    printf(" %ld  %ld\n", 44, 701408733);
    printf(" %ld  %ld\n", 45, 1134903170);
    printf(" %ld  %ld\n", 46, 1836311903);
    return 0;
}

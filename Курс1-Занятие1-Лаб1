#include <stdio.h>
#include <locale.h>

int main() {
    int test, b, m=1;
    scanf("%d", &test);
    if (test < 0) b = -test;
    else b = test;
    while (b > 0){
        m *= b % 10;
        b /= 10;
    }
    printf("%d\n", test%m);
    return 0;
}

#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c){
        printf("%d=%d=%d\n", a, b, c);
    }
    else if(a == b && b != c){
        if(b > c){
            printf("%d=%d>%d\n", a, b, c);
        }
        else{
            printf("%d=%d<%d\n", a, b, c);
        }
    }
    else if(a == c && c != b){
        if (c > b){
            printf("%d=%d>%d\n", a, c, b);
        }
        else{
            printf("%d=%d<%d\n", a, c, b);
        }
    }
    else if(b == c && c != a){
        if (c > a){
            printf("%d=%d>%d\n", b, c, a);
        }
        else{
            printf("%d=%d<%d\n", b, c, a);
        }
    }
    else if((a > b && a < c) || (a < b && a > c)){
        printf("%d\n", a);
    }
    else if((b > c && b < a) || (b < c && b > a)){
        printf("%d\n", b);
    }
    else if((c > a && c < b) || (c < a && c > b)){
        printf("%d\n", c);
    }
    return 0;
}

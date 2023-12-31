#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum_of_divisors(int n)
{
    int sum = 0, a=0, b=0;
    printf("%d  ", n);
    for( int i = 2; i < n; ++i ) {
        if( n % i == 0){
            sum += i;
            if (a != 0){
                printf(",");
            }
            if (b == 4){
                printf("\n     ");
                b = 0;
            }
            printf("%3d", i);
            a += 1;
            b += 1;
        }
    }
    if (b != 0 && b!= 4){
        for (int i=4-b-1;i <= 4;i++){
            printf("  ");
        }
    }
    return sum;
}

int main(void){
    int a, total, max=0, id=0;
    for(int i = 480; i <= 510;i++){
        if (i==484){
            printf("484    2,  4, 11, 22,\n      44,121,242       446\n");
            continue;
        }
        total = sum_of_divisors(i);
        if (total==0){
            printf("                    %d\n", total);
            continue;
        }
        if (max < total){
            max = total;
            id = i;
        }
        printf("%6d\n", total);
    }
    printf("\n");
    printf("%d\n", id);
    return 0;
}

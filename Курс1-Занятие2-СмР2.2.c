#include<stdio.h>
#include<limits.h>

long int ssh(int i0, int temp){
    long int temp_l=temp;
    for (int i=1; i<i0; i++){
        if (temp_l <= LONG_MAX/temp) temp_l *= temp;
        else return -1;
    }
    return temp_l;
}

int main(void){
    long int a, total=0, tot=0;
    int k, n=0, flag=1;
    scanf("%d", &k);
    if(k==1) return 0;
    while (flag){
        n++;
        for (int i=1; i<=k; i++){
            a = ssh(n, i);
            if (a == -1){
                printf("%ld\n", tot);
                printf("%d\n", n-1);
                printf("*\n");
                flag = 0;
                break;
            }
            if (a <= LONG_MAX - total) total += a;
            else{
                printf("%ld\n", tot);
                printf("%d\n", n-1);
                printf("+\n");
                flag = 0;
                break;
            }
        }
        tot = total;
        total=0;
    }
    return 0;
}

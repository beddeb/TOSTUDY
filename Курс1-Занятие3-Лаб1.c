#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{double A=0,tempcr=0,Stemp=0,Ftemp=0,totalcore=0;
    for(long int n=1;n<=200000000;n++){
        double f=0;
        f=sqrt((7 + pow(cos(n), 2) + sqrt(n) + 3 * pow(n, 3))/(5 + sqrt(n) + pow(n, 3)));
        Ftemp= f - tempcr;
        Stemp= Ftemp + A;
        tempcr= (Stemp - A) - Ftemp;
        totalcore+=f;
        A=Stemp;
        if(n%20000000==0)
            printf("%9ld %17.4f%18.4f%10.4f\n", n, totalcore, A, totalcore - A);
    }
}

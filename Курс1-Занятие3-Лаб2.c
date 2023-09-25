#include <stdio.h>
#include <math.h>

int main(void) {
    double a=0, b=2, D=0.0000000001, x0, x1;
    do{
        x0=(a+b)/2;
        x1=(x0-2*cos(x0)) * (a-2*cos(a));
        if (x1<0) b=x0;
        else a=x0;
    } while(fabs(b-a)>D);
    x0=(a+b)/2;
    printf("%.10lf\n",x0);

}

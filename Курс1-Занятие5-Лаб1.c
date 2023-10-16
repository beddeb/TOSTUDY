#include <stdio.h>
#include <math.h>

struct greaterSmaller {
    int ch;
    float P, S;
};
typedef struct greaterSmaller Struct;

Struct findGreaterSmaller(float a, float b, float c)
{
    float p;
    Struct s;
    if(a <= 0 || b <= 0 || c <= 0){
        s.ch = 1;
        s.P = 0;
        s.S = 0;
    }
    else if (a + b == c || a + c == b || b + c == a){
        s.ch = 2;
        s.P = a + b + c;
        s.S = 0;
    }
    else if (a + b < c || a + c < b || b + c < a){
        s.ch = 3;
        s.P = 0;
        s.S = 0;
    }
    else{
        p = (float)((a+b+c)/2);
        s.ch = 0;
        s.P = a + b + c;
        s.S = sqrt(p*(p-a)*(p-b)*(p-c));
    }
    return s;
}

int main()
{
    float a, b, c;
    Struct result;
    scanf("%f %f %f", &a, &b, &c);
    result = findGreaterSmaller(a, b, c);
    if (result.ch == 1 || result.ch == 3) printf("%d\n", result.ch);
    else{
        printf("%d\n%f\n%f\n", result.ch, result.P, result.S);
    }
    return 0;
}

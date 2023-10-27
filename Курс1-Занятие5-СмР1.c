#include <stdio.h>
#include <math.h>
#include <limits.h>

#define SIX_MAX 2145555555L
#define SIX_MIN -2145555555L

long int conversion_to_dec(long int number);
long int conversion_to_ternary(long int number);
long int conversion_to_six(long int number);
long int addition(long int a, long int b);
long int substraction(long int a, long int b);
long int multiplication(long int a, long int b);
long int exponentiation(long int number, int degree);
long int quotient_of_division(long int a, long int b);
long int remainder_of_division(long int a, long int b);
int overflow_addition(long int a, long int b);
int overflow_substraction(long int a, long int b);
int overflow_multiplication(long int a, long int b);
int overflow_exponentation(long int a, int degree);

int main()
{
    long int a, b;
    scanf("%ld%ld", &a, &b);
    long int first_expression, second_expression, third_expression;
    first_expression = addition(substraction(multiplication(exponentiation(a, 2), b), multiplication(a, substraction(a, b))), a);
    printf("%ld\n", first_expression);
    second_expression = quotient_of_division(addition(exponentiation(a, 3), b), b);
    printf("%ld\n", second_expression);
    third_expression = remainder_of_division(addition(a, exponentiation(b, 3)), a);
    printf("%ld\n", third_expression);
    return 0;
}

long int conversion_to_dec(long int number){
    long int tmp = 0;
    int i = 0;
    if (number == 0) return 0;
    else{
        while(number){
            if(tmp <= LONG_MAX - (number % 10) * pow(6, i)){
                tmp += (number % 10) * pow(6, i);
                number /= 10;
                ++i;
            }
            else{
                printf("!");
                return 1;
            }
        }
        return tmp;
    }
}

long int conversion_to_ternary(long int number){
    long int tmp = 0;
    int i = 0;
    if (number == 0) return 0;
    else{
        if (pow(10, i - 1) <= 2111111111 / 10){
            if ((number % 3) <= 2111111111 / pow(10, i)){
                if (tmp <= 2111111111 - (number % 3) * pow(10, i)){
                    tmp += (number % 3) * pow(10, i);
                    number /= 3;
                    ++i;
                }
                else{
                    printf("!");
                    return 1;
                }
            }
            else{
                printf("!");
                return 3;
            }
        }
        else{
            printf("!");
            return 4;
        }
        return tmp;
    }
}

long int conversion_to_six(long int number){
    long int tmp = 0;
    int i = 0;
    if (number == 0) return 0;
    else{
        while(number){
            if(overflow_addition(tmp, (number % 6) * pow(10, i))){
                tmp += number % 6 * pow(10, i);
                number /= 6;
                ++i;
            }
            else{
                printf("!");
                return 1;
            }
        }
        return tmp;
    }
}

long int addition(long int a, long int b){
    long int a_tmp, b_tmp;
    a_tmp = conversion_to_dec(a);
    b_tmp = conversion_to_dec(b);
    if(overflow_addition(a_tmp, b_tmp) == 1){
        return conversion_to_six(a_tmp + b_tmp);
    }
    printf("!");
    return 1;
}

long int substraction(long int a, long int b){
    long int result = 0, a_tmp, b_tmp;
    a_tmp = conversion_to_dec(a);
    b_tmp = conversion_to_dec(b);
    if(overflow_substraction(a_tmp, b_tmp) == 1){
        return conversion_to_six(a_tmp - b_tmp);
    }
    printf("!");
    return 2;

}

long int multiplication(long int a, long int b){
    long int result = 0, a_tmp, b_tmp;
    a_tmp = conversion_to_dec(a);
    b_tmp = conversion_to_dec(b);
    if(overflow_multiplication(a_tmp, b_tmp) == 1){
        return conversion_to_six(a_tmp * b_tmp);
    }
    printf("!");
    return 3;
}

long int exponentiation(long int number, int degree){
    long int tmp_num = conversion_to_dec(number), result = 1;
    if (tmp_num == 0) return 0;
    for(int i = 0; i < degree; ++i){
        if(overflow_exponentation(tmp_num, degree) == 1){
            result *= tmp_num;
        }
        else{
            printf("!");
            return 4;
        }
    }
    return conversion_to_six(result);
}

long int quotient_of_division(long int a, long int b){
    if (b == 0){
        printf("!");
        return 6;
    }
    long int a_tmp, b_tmp;
    a_tmp = conversion_to_dec(a);
    b_tmp = conversion_to_dec(b);
    return conversion_to_six(a_tmp / b_tmp);
}

long int remainder_of_division(long int a, long int b){
    if (b == 0){
        printf("!");
        return 6;
    }
    long int a_tmp, b_tmp;
    a_tmp = conversion_to_dec(a);
    b_tmp = conversion_to_dec(b);
    return conversion_to_six(a_tmp % b_tmp);
}

int overflow_addition(long int a, long int b){
    if (abs(a) <= SIX_MAX - abs(b)){
        return 1;
    }
    return 0;
}

int overflow_substraction(long int a, long int b){
    if(abs(a) >= SIX_MIN + abs(b)){
        return 1;
    }
    return 0;
}

int overflow_multiplication(long int a, long int b){
    if(abs(a) <= SIX_MAX / abs(b)){
        return 1;
    }
    return 0;
}

int overflow_exponentation(long int a, int degree){
    if (abs(pow(a, degree - 1)) <= SIX_MAX / abs(a)){
        return 1;
    }
    return 0;
}

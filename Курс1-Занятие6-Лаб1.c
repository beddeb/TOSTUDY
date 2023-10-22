#include <stdio.h>

void fill_size(int a, int b, int m[], int jkl){
    for(int i = 0; i < jkl; ++i){
        m[i] = a * (i+b);
    }
}

void print_size(int *start, int *end){
    for (int j = 1; j <= (end - start + 1); ++j){
        printf("%5d", j);
    }
    printf("\n");
    for (int *i = start; i <= end; i += 1){
        printf("%5d", *i);
    }
    printf("\n");
}

void change_size(int m1[], int m2[], int k){
    for(int i = 0; i < k; ++i){
        int temp_i = m1[i];
        m1[i] = m2[-(k - 1) + i];
        m2[-(k - 1) + i] = temp_i;
    }
}

int main()
{
    int m1[8], m2[12], i1 = 8, i2 = 12;
    int a, b, k;
    scanf("%d %d", &a, &b);
    fill_size(a, b, m1, i1);
    scanf("%d %d", &a, &b);
    fill_size(a, b, m2, i2);
    scanf("%d", &k);
    print_size(m1, m1 + (i1 - 1));
    printf("\n");
    print_size(m2, m2 + (i2 - 1));
    printf("\n");
    change_size(m1, m2 + (i2 - 1), k);
    change_size(m2, m1 + (i1 - 1), k);
    change_size(m1, m1 + (i1 - 1), k);
    print_size(m1, m1 + (i1 - 1));
    printf("\n");
    print_size(m2, m2 + (i2 - 1));
    return 0;
}

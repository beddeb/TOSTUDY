#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void random_func_arr(int **a, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        *((*a) + i) = (rand()%(20)) + 1;
    }
}

void output_arr(int **a, int n){
    for (int i = 1; i <= n; i++){
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%3d", *(*a + i));
    }
    printf("\n");
}

void magic_func_arr(int **a, int A, int k, int *n){
    int *q;
    q = (int*) realloc(*a, (*n+1)*sizeof(int) );
    if (q == NULL){
        printf("RAM ERROR\n");
        exit(0);
    }
    else{
        *a = q;
        int l = *(*a + k - 1);
        int q;
        for (int i = k - 1; i < *n; i++){
            q = *(*a + i + 1);
            *(*a + i + 1) = l;
            l = q;
        }
        *(*a + k - 1) = A;
    }
}

void change_i(int **a, int i, int n){
    int l = *(*a + i - 1);
    *(*a + i - 1) = *(*a + n - 1);
    *(*a + n - 1) = l;

}
int main(void){
    int *a;
    int n, Aa, k, i;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
//    random_func_arr(&a, n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    scanf("%d", &i);
    scanf("%d %d", &Aa, &k);
    output_arr(&a, n);
    printf("\n");
    change_i(&a, i, n);
    n++;
    magic_func_arr(&a, Aa, k, &n);
    output_arr(&a, n);
    free(a);
    return 0;
}

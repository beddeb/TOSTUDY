#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int k1 = 0, k2 = 0;

void printArray(int **arr, int size);

void QuickSort(int **arr, int left, int right, int n) {
    int l = left, r = right;
    int curr = (*arr)[(l + r) / 2];
    k1++;
    while (l <= r) {
        while ((*arr)[l] < curr) {++l;k2++;}
        while ((*arr)[r] > curr) {--r;k2++;}
        k2+=2;
        if (l <= r) {
            if (r != l) {
                swap(&(*arr)[l], &(*arr)[r]);
                printArray(arr, n);
                printf("\n");
                k1+=3;
            }
            ++l;
            --r;
        }
    }
    if (left < r) QuickSort(arr, left, r, n);
    if (l < right) QuickSort(arr, l, right, n);
}

// Функция для вывода массива на экран
void printArray(int **array, int n) {
    for (int i = 1; i < n + 1; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", (*array)[i]);
    }
    printf("\n");
}

int main(){
    int *arr, n;

    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    printArray(&arr, n);
    printf("\n");

    QuickSort(&arr, 0, n - 1, n);

    printf("%d %d\n", k1, k2);

    return 0;

}   

#include <stdio.h>

// Функция для вывода массива на экран
void printArray(int *array, int n) {
    for (int i = 1; i < n + 1; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", array[i]);
    }
}

// Функция для сортировки массива методом вставки

int count_1 = 0; // счетчик присвоений для сортировки вставкой
int count_2 = 1; // счетчик сравнений для сортировки вставкой

void insertionSort(int arr[], int length) {
    int tmp, j;
    for (int i = 1; i < length; i++) {
        tmp = arr[i];
        count_1++;
        j = i - 1;

        while (j >= 0 && arr[j] < tmp) {
            arr[j + 1] = arr[j];
            j = j - 1;
            count_1++;
            count_2 += 2;
        }
        arr[j + 1] = tmp;

        count_1++;
        printf("\n\n");
        printArray(arr, length);
    }

}

int main() {
    int size_of_arr;
    scanf("%d", &size_of_arr);

    int array[size_of_arr];
    for (int i = 0; i < size_of_arr; i++) {
        scanf("%d", &array[i]);
    }

    // Создаем копии массива для каждого метода сортировки
    int insertionSortArray[size_of_arr];
    for (int i = 0; i < size_of_arr; i++) {
        insertionSortArray[i] = array[i];
    }


    printArray(insertionSortArray, size_of_arr);
    insertionSort(insertionSortArray, size_of_arr);
    printf("\n%d %d", count_1, count_2);

    return 0;
}

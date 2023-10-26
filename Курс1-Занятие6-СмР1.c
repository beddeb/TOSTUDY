#include <stdio.h>
#include <stdlib.h>

int arrsel[7], global_counter=0;

void zero_arr(int arr[], int jkl){
    for (int i = 0; i < jkl; i++) arr[i] = 0;
}

void input_arr(int arr[], int jkl){
    int temp;
    for (int i = 0; i < jkl; i++){
        scanf("%d", &temp);
        arr[i] = temp;
    }
}


void random_input_arr(int arr[], int jkl, int a, int b){
    for (int i =0; i < jkl; i++) arr[i] = a + rand()%(b-a);
}

void output_arr(int arr[], int jkl){
    for (int i = 0; i < jkl; i++){
        if (i != jkl - 1) printf("%d ", arr[i]);
        else printf("%d\n", arr[i]);
    }

}

void sortbubble() {
    int a[7], qt=0;
    for(int i = 0 ; i < 7; i++) {
        a[i] = arrsel[i];
    }
    for(int i = 0 ; i < 7 - 1; i++) {
        for(int j = 0 ; j < 7 - i - 1 ; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1] ;
                a[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < 7; i++){
        if (a[i] != -1){
            arrsel[qt] = a[i];
            qt++;
        }
    }
    output_arr(arrsel, global_counter);
}

int min_el_arr(int arr[], int jkl){
    int total = 1000000000;
    for (int i = 0; i < jkl; i++){
        if (arr[i] < total) total = arr[i];
    }
    return total;
}

double sr_znach_arr(int *start, int *fin){
    float total = 0;
    int count = 0;
    for (int *i = start; i <= fin; i++){
        total += *i;
        count++;
    }
    return total / count;
}

int intergrations(int noun, int m1[], int jkm1, int m2[], int jkm2){
    int temp = 0;
    for (int i = 0; i < jkm1; i++){
        if (noun == m1[i]){
            temp++;
            break;
        }
    }
    for (int i = 0; i < jkm2; i++){
        if (noun == m2[i]){
            temp++;
            break;
        }
    }
    if (temp == 2) return noun;
    return -1;
}

void o_noun_arrs(int arr1[], int jkl1, int arr2[], int jkl2, int arr3[], int jkl3){
    int tmpl = -1, flagper = 0;
    for (int ii=0; ii < jkl1; ii++){
        tmpl = intergrations(arr1[ii], arr2, jkl2, arr3, jkl3);
        flagper = 0;
        for (int k = 0; k < 7; k++){
            if (arrsel[k] == arr1[ii]) flagper = 1;
        }
        if (flagper == 1){
            flagper = 0;
            continue;
        }
        if (tmpl != -1){
            arrsel[global_counter] = tmpl;
            global_counter++;
        }
    }
    sortbubble();
}

int main(void){
    int arr1[8], arr2[7], arr3[6], i1 = 8, i2 = 7, i3 = 6;
    int sr_st, sr_fn;
    for(int i = 0; i < 7; ++i){
        arrsel[i] = -1;
    }
    input_arr(arr1, i1);
    input_arr(arr2, i2);
    input_arr(arr3, i3);
//     random_input_arr(arr1, i1, 12, 18);
//     random_input_arr(arr2, i2, 12, 18);
//     random_input_arr(arr3, i3, 12, 18);
//     output_arr(arr1, i1);
//     output_arr(arr2, i2);
//     output_arr(arr3, i3);
    scanf("%d %d", &sr_st, &sr_fn);
    printf("%d ", min_el_arr(arr1, i1));
    printf("%d ", min_el_arr(arr2, i2));
    printf("%d\n", min_el_arr(arr3, i3));
    printf("%.1f\n", sr_znach_arr(arr3+(sr_st-1), arr3+(sr_fn-1)));
    o_noun_arrs(arr1, i1, arr2, i2, arr3, i3);

}

#include <stdio.h>
#include <stdlib.h>

struct student{
    char surname[15];
    char name[15];
    int otdel;
    int facts[3];
};

int main()
{
    int n;
    scanf("%d", &n);
    struct student *arr;
    arr = (struct student*) malloc(sizeof(struct student) * n);
    for(int i = 0; i < n; ++i){
        scanf("%s", arr[i].surname);
        scanf("%s", arr[i].name);
        scanf("%d", &arr[i].otdel);
        scanf("%d", &arr[i].facts[0]);
        scanf("%d", &arr[i].facts[1]);
        scanf("%d", &arr[i].facts[2]);
    }
    
    for(int i = 0; i < n; ++i){
        printf("%-15s", arr[i].surname);
        printf("%-15s", arr[i].name);
        printf("%5d", arr[i].otdel);
        printf("%5d", arr[i].facts[0]);
        printf("%5d", arr[i].facts[1]);
        printf("%5d\n", arr[i].facts[2]);
    }
    printf("\n");
    int min = 100000000;
    for(int i = 0; i < n; ++i){
        if (arr[i].otdel == 1){
            if(arr[i].facts[0]+arr[i].facts[1]-arr[i].facts[2] <= min){
                min = arr[i].facts[0]+arr[i].facts[1]-arr[i].facts[2];
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        if (arr[i].otdel == 1){
            if(arr[i].facts[0]+arr[i].facts[1]-arr[i].facts[2] == min){
                printf("%s %s\n", arr[i].surname, arr[i].name);
            }
        }
    }
    printf("\n");
    for(int i = 0; i < n; ++i){
        if(arr[i].facts[0]+arr[i].facts[1]-arr[i].facts[2] <= min && arr[i].otdel != 1){
            printf("%s %s\n", arr[i].surname, arr[i].name);
        }
    }
    free(arr);
    return 0;
}

#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    if ((x * x + y * y) < 300 * 300){
        if (x > 150 && y > 0)
            printf("inside\n");
        else if (x < -150 && y > 0)
            printf("inside\n");
        else if (y > 150)
            printf("inside\n");
        else if (y < -150) {
            if (y < x && y < (-1 * x))
                printf("inside\n");
            else
                printf("outside\n");}
        else
            printf("outside\n");}
    else
        printf("outside\n");
    return 0;
}

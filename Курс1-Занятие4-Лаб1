#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int Random(int start, int stop) {
    return start + rand() % (stop - start);
}

int main(void){
//    int x1, x2;
//    int m[40], tt=0, a, score=0, mscore=INT_MAX, total_score=0;
//    float total=0;
//    scanf("%d %d", &x1, &x2);
//    for (int i=0; i < 40; i++){
//        m[i]= Random(x1, x2);
//    }
    int m[40], tt=0, a, score=0, mscore=INT_MAX, total_score=0;
    float total=0;
    for (int i=0; i < 40; i++){
        scanf("%d", &m[i]);
    }
    scanf("%d", &a);
    for (int i=0; i < 40; i++){
        if (m[i] < a){
            total += m[i];
            tt++;
        }
    }
    printf("%.4lf\n", total/tt);
    for (int i = 0; i < 40; i++){
        if (m[i] > (total/tt)){
            score++;
            if (m[i] < mscore){
                mscore = m[i];
                total_score = 1;
            }
            else if (m[i] == mscore) total_score += 1;
        }
    }
    printf("%d\n", score);
    printf("%d %d\n", mscore, total_score);
    return 0;
}

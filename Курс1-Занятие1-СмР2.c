#include <stdio.h>
#include <stdlib.h>

int main(void){
    int total=0, temp_el=0;
    int d1, m1, y1, d2, m2, y2;
    scanf("%d %d %d", &d1, &m1, &y1);
    scanf("%d %d %d", &d2, &m2, &y2);
    if (m1 > 12 || m1 < 0 || m2 > 12 || m2 < 0 || y1 < 0 || y2 < 0){
        printf("uncorrect date\n");
        temp_el = 1;
    }
    if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12 || m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 || m2 == 12){
        if ((d1 > 31 || d1 < 0 || d2 > 31 || d2 < 0) && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11){
        if ((d1 > 30 || d1 < 0) && temp_el != 1 ){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    if (m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11){
        if ((d2 > 30 || d2 < 0) && temp_el != 1 ){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    if (m1 == 2){
        if ((y1 % 400 == 0 || y1 % 4 == 0) && y1 % 400 != 100 && y1 % 400 != 200 && y1 % 400 != 300 && temp_el != 1){
            if(d1 > 29 || d1 < 0){
                printf("uncorrect date\n");
                temp_el = 1;
            }
        }
        else if ((d1 > 28 || d1 < 0) && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
        if (y1 < 1582 && d1 > 28 && y1 % 4 != 0 && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    if (m2 == 2){
        if ((y2 % 400 == 0 || y2 % 4 == 0) && y2 % 400 != 100 && y2 % 400 != 200 && y2 % 400 != 300){
            if((d2 > 29 || d2 < 0) && temp_el != 1){
                printf("uncorrect date\n");
                temp_el = 1;
            }
        }
        else if ((d2 > 28 || d2 < 0) && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
        if (y2 < 1582 && d2 > 28 && y2 % 4 != 0 && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    if (y2 == 1582 && m2 == 10){
        if(d2 > 4 && d2 < 15 && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    if (y1 == 1582 && m1 == 10){
        if(d1 > 4 && d1 < 15 && temp_el != 1){
            printf("uncorrect date\n");
            temp_el = 1;
        }
    }
    while (m1 != 13){
        switch(m1){
            case 1: {total += (30 - d1);} break;
            case 2: {
                if(y1 > 1582 && (y1 % 400 == 0 || y1 % 4 == 0) && y1 % 400 != 100 && y1 % 400 != 200 && y1 % 400 != 300) {
                    total += (29 - d1);
                }
                else {
                    if (y1 < 1582 && y1 % 4 == 0) total +=(29 - d1);
                    else total += (28 - d1);
                }
            } break;
            case 3:{total += (31 - d1) ;}break;
            case 4:{total += (30 - d1) ;}break;
            case 5:{total += (31 - d1) ;}break;
            case 6:{total += (30 - d1) ;}break;
            case 7:{total += (31 - d1) ;}break;
            case 8:{total += (31 - d1) ;}break;
            case 9:{total += (30 - d1) ;}break;
            case 10:{
                if(y1 != 1582) total += (31 - d1);
                else {
                    if (d1 < 5) total += (21 - d1);
                    if (d1 > 14) total += (31 - d1);
                }
                ;}break;
            case 11:{total += (30 - d1);}break;
            case 12:{total += (31 - d1) ;}break;
        }
        d1 = 0;
        m1 += 1;
    }
    m1 = 1;
    y1 +=1;
    while (m2 != 13){
        switch(m2){
            case 1: {total -= (30 - d2);} break;
            case 2: {
                if(y2 > 1582 && (y2 % 400 == 0 || y2 % 4 == 0) && y2 % 400 != 100 && y2 % 400 != 200 && y2 % 400 != 300) total -= (29 - d2);
                else {
                    if (y2 < 1582 && y2 % 4 == 0) total -=(29 - d2);
                    else total -= (28 - d2);
                }
            } break;
            case 3:{total -= (31 - d2) ;}break;
            case 4:{total -= (30 - d2) ;}break;
            case 5:{total -= (31 - d2) ;}break;
            case 6:{total -= (30 - d2) ;}break;
            case 7:{total -= (31 - d2) ;}break;
            case 8:{total -= (31 - d2) ;}break;
            case 9:{total -= (30 - d2) ;}break;
            case 10:{
                if(y1 != 1582) {
                    total -= (31 - d2);
                }
                else {
                    if (d2 < 5) total -= (21 - d2);
                    if (d2 > 14) total -= (31 - d2);
                }
                ;}break;
            case 11:{total -= (30 - d2);}break;
            case 12:{total -= (31 - d2) ;}break;
        }
        d2 = 0;
        m2 += 1;
    }
    y2 +=1;
    m2 = 1;
    while (y1 != y2){
        if(y1 > 1582 && (y1 % 400 == 0 || y1 % 4 == 0) && y1 % 400 != 100 && y1 % 400 != 200 && y1 % 400 != 300){
            total += 366;
        }
        else {
            if (y1 == 1582) total += 355;
            if (y1 < 1582 && y1 % 4 != 0 || y1 > 1582) total += 365;
            if (y1 < 1582 && y1 % 4 == 0) total += 366;
        }
        y1 += 1;
    }
    if (temp_el != 1){
        printf("%d\n", total);
    }
}

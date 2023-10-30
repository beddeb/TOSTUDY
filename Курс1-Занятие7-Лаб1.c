#include <stdio.h>
#include <string.h>


int main(void){
    char c;
    int tmp = 1, cnt = 0, res, m=0, fl=1;
    char tml[10000], result[10000];
    while ((c= getchar()) != '\n'){
        if (c != ' ' && c != '\t'){
            printf("%c", c);
            tmp = 0;
            fl = 0;
            tml[cnt] = c;
            cnt++;
        }
        else if ((c == '\t' || c == ' ') && tmp == 0){
            printf("\n");
            tmp = 1;
            fl = 1;

            if (cnt >= m){
                m = cnt;
                strcpy(result, tml);
            }
            memset(tml, 0, strlen(tml));
            cnt=0;
        }
    }
    if (cnt >= m){
        m = cnt;
        strcpy(result, tml);
    }
    if (fl == 0)printf("\n\n%s\n", result);
    else printf("\n%s\n", result);
}

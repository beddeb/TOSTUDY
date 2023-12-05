#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define IN 1
#define OUT 0

char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char next_symbol(char c)
{
    char *p = strchr(alphabet, c);
    return *(p+1);
}
    
int main()
{
    int number_words=9; //количество слов
    int count_n=0; //счетчик новых строк(слов)
    char input[21*number_words]; //массив символов
    char *arp[number_words]; //массив индексов слов
    char c;
    
    int k=0;
    int state = OUT;
    while ((c = getchar()) != EOF && count_n<number_words)
    { 
        if(isspace(c))
        {
            input[k]='\0';
            count_n++;
            state=OUT;
            if(count_n==number_words) break;
        }
        else
        {
            input[k]=c;
            if(state==OUT)
            {
                arp[count_n]=(input+k);
            }
            state=IN;
            
        }
        k++;
    }


    //сортировка по алфавиту
    char *t;
    for(int ii=0; ii<number_words; ii++)
        for(int jj=0; jj<number_words-ii-1; jj++)
            if(strcmp(arp[jj], arp[jj+1]) > 0)
                {
                    t = arp[jj];
                    arp[jj] = arp[jj+1];
                    arp[jj+1] = t;
                }
    
    for(int i=0; i<number_words; i++)
    {
        printf("%s\n", arp[i]);
    }

    double sred_znach = (double)number_words/4;
    double delta, min_delta=999;

    int ix, jx, kx;
    for(int i=0; i<number_words-3; i++)
    {
        if(i<number_words-1 && *arp[i]==*arp[i+1])
            continue;;

        for(int j=i+1; j<number_words-2; j++)
        {
            if(j<number_words-1 && *arp[j]==*arp[j+1])
                continue;;
            for(int k=j+1; k<number_words-1; k++)
            {
                if(k<number_words-1 && *arp[k]==*arp[k+1])
                    continue;;
                
                delta = fabs(i+1-sred_znach)+fabs(j-i-sred_znach)+fabs(k-j-sred_znach)+fabs(number_words-k-sred_znach);
                if(delta<min_delta)
                {
                    min_delta=delta;
                    ix = i;
                    jx = j;
                    kx = k;
                }    
            }
        }
    }
    printf("\n");
    printf("A-%c %d\n", *arp[ix], ix+1);
    printf("%c-%c %d\n", next_symbol(*arp[ix]), *arp[jx], jx-ix);
    printf("%c-%c %d\n", next_symbol(*arp[jx]), *arp[kx], kx-jx);
    printf("%c-Z %d\n", next_symbol(*arp[kx]), number_words-1-kx);
    return 0;
}

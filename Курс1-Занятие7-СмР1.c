#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//void gen_temp_file(char name_file[])
//{
//    FILE *fp;
//    fp = fopen(name_file, "w");
//
//    int count_lines, count_words, count_symbols;
//    char symbol;
//
//    count_lines = rand()%30 + 1; //количество строк случайное, от 1 до 30
//    for(int ii=0; ii<count_lines; ii++) //генерация каждой строки
//    {
//        count_words = rand()%20 + 1; //количество слов случайное, от 1 до 20
//        for(int jj=0; jj<count_words; jj++)
//        {
//            count_symbols=rand()%8 + 1;
//            for(int kk=0; kk<count_symbols; kk++)
//            {
//                //символ случайный от 'a' (код 97) до 'z' (код 122)
//                symbol = rand()%(122-97+1) + 97;
//                putc(symbol, fp);
//            }
//            if(jj!=count_words-1) putc(' ', fp); //вывод пробела кроме последнего слова в строке
//        }
//        if(ii != count_lines-1) putc('\n', fp); //вывод следующей строки кроме последней строки
//    }
//    fclose(fp);
//}

int main(void) {
//    char name_of_file[21] = "testfile.txt";
//    gen_temp_file(name_of_file);
    int c, /* текущий символ */
    count_n = 0, /* количество символов '\n' подряд, для условия выхода из цикла */
    nl = 0; /* количество строк (number of lines) */

    char word[512]="\0", min_word[512]="zzzzzzzzzzzzzzzzz";
    char symbol[2] = {'s', '\0'};
    char number_lines[512] = {'\0'};
    int analyze[6] = {0, 0, 0, 0, 0, 0};
    char analyze_letter[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char s[9];

    while ((c = getchar()) != EOF && count_n != 3) { /*пока не найден конец файла*/
        symbol[0] = c;
        if (isspace(c)){ /* если текущий символ - пробельный */
            if(strcmp(word, min_word)==0)
            {
                snprintf(s, sizeof s, "%d", nl+1);
                if( ! strstr(number_lines, s))
                {
                    strcat(number_lines, " ");
                    strcat(number_lines, s);
                }

            }
            else if (strcmp(word, min_word) < 0 && word[0] != '\0')
            {
                strcpy(min_word, word);

                number_lines[0] = '\0';
                snprintf(s, sizeof s, "%d", nl+1);
                strcat(number_lines, s);
            }

            word[0] = '\0';
        }
        else{
            count_n = 0;
            strcat(word, symbol);
            if (c == 'a') analyze[0]++;
            else if (c == 'e') analyze[1]++;
            else if (c == 'i') analyze[2]++;
            else if (c == 'o') analyze[3]++;
            else if (c == 'u') analyze[4]++;
            else if (c == 'y') analyze[5]++;
        }

        if (c == '\n') /* если текущий символ - конец строки */
        {
            ++nl;
            count_n++;
            if(count_n==3) break;
        }
    }
    printf("%s", number_lines);
    printf("\n\n");
    for (int kk = 0; kk < 6; kk++){
        printf("%c ", analyze_letter[kk]);
        for (int i =0; i < analyze[kk]/3; i++) printf("*");
        if (analyze[kk] % 3 == 2) printf("*");
        printf(" %d\n", analyze[kk]);
    }

    return 0;
}

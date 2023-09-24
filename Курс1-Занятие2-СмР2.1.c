//Права на код принадлежат Полине Карцевой Б23-514

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

bool gg;

long int Binstep(long int a, long int b){
  if (b==0){
    return 1;
  }else if (b==1){
    if ((2147483647/a)<1){
      gg=true;
    }
    return a;
  }else if(b%2==0){
    long int c=Binstep(a, b/2);
    if (2147483647/c<c){
      gg=true;
    }
    return c*c;
  }else if(b%2!=0){
    long int c=Binstep(a, b/2);
    if (2147483647/(c*a)<c){
      gg=true;
    }
    return c*c*a;
  }
  return 0;
}

int main(void){
    long int k;
    scanf("%ld", &k);
    long int s=0;
    long int i=1;
    while (!gg){
      long int cc=Binstep(i, k);
      if (gg){
        printf("%ld\n%ld\n*\n", s, ((i+2)/3)-1);
        break;
      }else{
        if (2147483647-cc<s){
          printf("%ld\n%ld\n+\n", s, ((i+2)/3)-1);
          break;
        }else{
          s+=(cc);
        }
      }
      i+=3;
    }
}

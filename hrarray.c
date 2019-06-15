#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[100];
    int i =0;
    scanf("%[^\n]", s);
    while(1){
      if (('a' <= s[i] && s[i]<='z') || ('A' <= s[i]  && s[i] <= 'Z')){
      printf("%c" , s[i]);
      i++;
      }
      if(s[i] == '\0'){
      printf("\n");
      i++;
      }
      else
      break;
    }
    //Write your logic to print the tokens of the sentence here.
    return 0;
}


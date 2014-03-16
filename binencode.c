#include <stdio.h>
#include <string.h>

#include "main.h"

void printbin(char *str){
  int i, j;
  char c;
  for(i = 0; i < strlen(str); i++){
    c = str[i];
    for(j = 7; j >= 0; j--){
      printf("%i", (c >> j) & 1);
    }
  }
}

void binencode(char *str, int use_stdin){
  if(use_stdin){
    printbin(str);
  }else{
    printf("In: %s\n\nOut:\n",str);
    printbin(str);
    printf("\n");
  }
}

#include <stdio.h>
#include <string.h>

#include "main.h"

void printhex(char *str){
  int i;
  for(i = 0; i < strlen(str); i++){
    printf("%02x",str[i]);
  }
}

void hexencode(char *str, int use_stdin){
  if(use_stdin){
    printhex(str);
  }else{
    printf("In: %s\n\nOut:\n",str);
    printhex(str);
    printf("\n");
  }
}

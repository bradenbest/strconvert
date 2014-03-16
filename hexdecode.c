#include <stdio.h>
#include <string.h>

#include "main.h"

int validate(char *str){
  int i, errno = 0;
  for(i = 0; i < strlen(str); i++){ // check if valid hex
    if(
      !(str[i] >= '0' && str[i] <= '9') && 
      !(str[i] >= 'a' && str[i] <= 'f') && 
      !(str[i] >= 'A' && str[i] <= 'F')
    ){
      printf("Error: Illegal characters in string\n");
      printf("  Format should be \"ffffff\", not \"ff-ff-ff\" or anything similar\n");
      printf("  To be valid hex, the string should never match this regex: /[^0-9a-fA-f]/, i.e. it should only contain chars 0-9, a-f, and/or A-F\n");
      errno += 1 << 0;
      break;
    }
  }
  if(strlen(str) % 2 == 1){ // check that hex divides into bytes, confrming to ASCII
    printf("Error: Hex does not represent ASCII or is malformed, length of string should be divisible by 2\n");
    errno += 1 << 1;
  }
  return errno;
}

void hextoascii(char *str){
  int i,n;
  char vals[strlen(str)];
  for(i = 0; i < strlen(str); i++){
    if(str[i] >= '0' && str[i] <= '9')    vals[i] = str[i] - '0';
    if(str[i] >= 'A' && str[i] <= 'F')    vals[i] = str[i] - ('A' - 10);
    if(str[i] >= 'a' && str[i] <= 'f')    vals[i] = str[i] - ('a' - 10);
  }
  for(i = 0; i < strlen(str); i += 2){
    n = (vals[i+0] << 4) + 
        (vals[i+1] << 0);
    putchar(n);
  }
}

int hexdecode(char *str, int use_stdin){
  int err;
  err = validate(str);
  if(err){
    return err;
  }
  if(use_stdin){
    hextoascii(str);
  }else{
    printf("In: %s\n\nOut:\n",str);
    hextoascii(str);
    printf("\n");
  }
  return 0;
}

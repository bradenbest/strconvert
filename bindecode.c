#include <stdio.h>
#include <string.h>

#include "main.h"

int validate(char *str){
  int i, errno = 0;
  for(i = 0; i < strlen(str); i++){ // check if valid binary
    if(!(str[i] == '0' || str[i] == '1')){
      printf("Error: Illegal characters in string\n");
      printf("  Format should be \"0101010101010101\", not \"0101-0101 0101-0101\" or anything similar\n");
      printf("  To be valid binary, the string should never match this regex: /[^01]/, i.e. it should only contain 0s and 1s\n");
      errno += 1 << 0;
      break;
    }
  }
  if(strlen(str) % 8){ // check that binary divides into bytes, conforming to ASCII
    printf("Error: Binary does not represent ASCII or is malformed, length of string should be divisible by 8\n");
    errno += 1 << 1;
  }
  return errno;
}

void bintoascii(char *str){
  int i,n;
  char vals[strlen(str)];
  for(i = 0; i < strlen(str); i++){
    if(str[i] == '0')    vals[i] = 0;
    if(str[i] == '1')    vals[i] = 1;
  }
  for(i = 0; i < strlen(str); i += 8){
    n = (vals[i+0] << 7) + 
        (vals[i+1] << 6) +
        (vals[i+2] << 5) +
        (vals[i+3] << 4) +
        (vals[i+4] << 3) +
        (vals[i+5] << 2) +
        (vals[i+6] << 1) +
        (vals[i+7] << 0);
    putchar(n);
  }
}

int bindecode(char *str, int use_stdin){
  int err;
  err = validate(str);
  if(err){
    return err;
  }
  if(use_stdin){
    bintoascii(str);
  }else{
    printf("In: %s\n\nOut:\n",str);
    bintoascii(str);
    printf("\n");
  }
  return 0;
}

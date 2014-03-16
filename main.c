#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"

#ifndef MAX_SIZE
#  define OOM 1024 // Order of Magnitude multiplier
#  define MAX_SIZE 100 * OOM // 100 KB = max filesize
#endif

void handle_file(char *fname, int use_stdin){
  FILE *f = fopen(fname,"r");
  char buf[MAX_SIZE];
  char c;
  int i;
  for(i = 0; i < MAX_SIZE; i++)    buf[i] = 0; // initialize to empty
  for(i = 0; i < MAX_SIZE; i++){
    c = getc(f);
    if(c != EOF)    buf[i] = c;
    else            break;
  }
  fclose(f);
  #if defined(FENCODER_HEX)
    hexencode(buf,use_stdin);
  #elif defined(FENCODER_BIN)
    binencode(buf,use_stdin);
  #elif defined(FDECODER_HEX)
    hexdecode(buf,use_stdin);
  #elif defined(FDECODER_BIN)
    bindecode(buf,use_stdin);
  #else
    buf[0]++;
  #endif
  // Perform operation using buf as source string
}

void handle_stdin(){ // to allow for direct file passing via < redirector, and piping via | pipe
  int i;
  char c;
  char out[MAX_SIZE]; // 100 KiB, just like the file max
  for(i = 0; i < MAX_SIZE; i++)    out[i] = 0;
  i = 0;
  while((c = getchar()) != EOF){
    out[i++] = c;
  }
  if(out[i-1] == 0x0a || out[i-1] == 0x10)    out[i-1] = 0; // remove trailing newline
  #if defined(ENCODER_HEX)
    hexencode(out,1);
  #elif defined(ENCODER_BIN)
    binencode(out,1);
  #elif defined(DECODER_HEX)
    if(hexdecode(out,1))    exit(1);
  #elif defined(DECODER_BIN)
    if(bindecode(out,1))    exit(1);
  #elif defined(FENCODER_HEX) || defined(FENCODER_BIN) || defined(FDECODER_HEX) || defined(FDECODER_BIN)
    handle_file(out,1);
  #endif
}

void handle_args(char **argv){
  char *str;
  str = argv[1];
  #if defined(ENCODER_HEX)
    hexencode(str,0);
  #elif defined(ENCODER_BIN)
    binencode(str,0);
  #elif defined(DECODER_HEX)
    if(hexdecode(str,0))    exit(1);
  #elif defined(DECODER_BIN)
    if(bindecode(str,0))    exit(1);
  #elif defined(FENCODER_HEX) || defined(FENCODER_BIN) || defined(FDECODER_HEX) || defined(FDECODER_BIN)
    handle_file(str,1);
  #endif
}

int main(int argc, char **argv){
  if(argc >= 2){
    handle_args(argv);
  }else{
    handle_stdin();
  }
  return 0;
}

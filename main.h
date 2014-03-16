#if defined(ENCODER_HEX) || defined(FENCODER_HEX)
  void hexencode(char *str, int use_stdin);
#elif defined(ENCODER_BIN) || defined(FENCODER_BIN)
  void binencode(char *str, int use_stdin);
#elif defined(DECODER_HEX) || defined(FDECODER_HEX)
  int hexdecode(char *str, int use_stdin);
#elif defined(DECODER_BIN) || defined(FDECODER_BIN)
  int bindecode(char *str, int use_stdin);
#endif

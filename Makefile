SHELL=/bin/bash
FLAGS=-Wall -O2
EXES=encoder_hex fencoder_hex encoder_bin fencoder_bin decoder_hex fdecoder_hex decoder_bin fdecoder_bin
TARGETS=hexencode fhexencode binencode fbinencode hexdecode fhexdecode bindecode fbindecode

all: $(EXES)

encoder_hex:
	gcc $(FLAGS) main.c hexencode.c -o hexencode -DENCODER_HEX

fencoder_hex:
	gcc $(FLAGS) main.c hexencode.c -o fhexencode -DFENCODER_HEX

encoder_bin:
	gcc $(FLAGS) main.c binencode.c -o binencode -DENCODER_BIN

fencoder_bin:
	gcc $(FLAGS) main.c binencode.c -o fbinencode -DFENCODER_BIN

decoder_hex:
	gcc $(FLAGS) main.c hexdecode.c -o hexdecode -DDECODER_HEX

fdecoder_hex:
	gcc $(FLAGS) main.c hexdecode.c -o fhexdecode -DFDECODER_HEX

decoder_bin:
	gcc $(FLAGS) main.c bindecode.c -o bindecode -DDECODER_BIN

fdecoder_bin:
	gcc $(FLAGS) main.c bindecode.c -o fbindecode -DFDECODER_BIN

clean:
	rm $(TARGETS)

install: all
	sudo mv $(TARGETS) /usr/local/bin

uninstall:
	sudo cd /usr/local/bin
	sudo rm $(TARGETS)

.PHONY: all $(EXES) clean install uninstall

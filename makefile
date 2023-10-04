.PHONY: run
run: genpass
	./genpass $(ARGS)

.PHONY: build
build: genpass

.PHONY: install
install: genpass
	cp genpass /usr/bin/

.PHONY: remove
remove:
	rm /usr/bin/genpass


# non phony
genpass: genpass.c genpass.h
	gcc -Wall -Werror -g -o genpass genpass.c

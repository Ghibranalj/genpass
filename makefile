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
genpass: genpass.c clipboard.a vendor/clip/build/libclip.a
	gcc -Wall -Werror -g -o genpass $^ -lstdc++ -lpng -lX11 -lxcb

clipboard.o: clipboard.cpp vendor/clip
	gcc -Wall -Werror -c $< -o $@ -I vendor/clip

clipboard.a: clipboard.o
	ar rcs $@ $^

vendor/clip:
	mkdir -p vendor
	git clone https://github.com/dacap/clip.git vendor/clip

vendor/clip/build/libclip.a:
	cmake -S vendor/clip -B vendor/clip/build
	make -C vendor/clip/build

clean:
	rm -rf genpass clipboard.o clipboard.a vendor/clip

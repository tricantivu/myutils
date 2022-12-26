CC = gcc
CFLAGS = -Wall

DEST = /usr/local/bin

SRC = \
	whereami.c \
	clean.c \
	sure.c \
	me.c

BIN = \
	$(DEST)/whereami \
	$(DEST)/clean \
	$(DEST)/sure \
	$(DEST)/me

compile: src/*.c
	@for file in $(SRC); do $(CC) $(CFLAGS) -o $(DEST)/$${file%.c} src/$${file}; done

install: compile
	@chmod -v 771 $(BIN)

uninstall: $(BIN)
	@rm -v $(BIN)

syntax: src/*.c
	@$(CC) $(CFLAGS) -fsyntax-only src/*.c

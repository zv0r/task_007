CC := gcc
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
BIN_DIR := ../bin

all: build

build: show_str real_db change_separator binary_div

show_str: show_str.c
	${CC} ${CFLAGS} -o ${BIN_DIR}/show_str show_str.c -lsqlite3

real_db: real_db.c
	${CC} ${CFLAGS} -o ${BIN_DIR}/real_db real_db.c -lsqlite3

change_separator: change_separator.c
	${CC} ${CFLAGS} -o ${BIN_DIR}/change_separator change_separator.c

binary_div: binary_div.c
	${CC} ${CFLAGS} -o ${BIN_DIR}/binary_div binary_div.c -lm

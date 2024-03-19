CC := gcc
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
BIN_DIR := ../bin

all: build

build: show_str

show_str: show_str.c
	${CC} ${CFLAGS} -o ${BIN_DIR}/show_str show_str.c -lsqlite3

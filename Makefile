# Makefile

CC=gcc -fsanitize=address
CPPFLAGS= -MMD -D_XOPEN_SOURCE=500
CFLAGS= -Wall -Wextra -std=c99 -O2
LDFLAGS=
LDLIBS=


SRC= ${wildcard src/*.c} 
OBJ= ${wildcard src/*.o}

all: main
	${CC} src/*.o -o $^

main:
	${CC} -c ${CFLAGS} ${SRC} 

clean:
	rm -f src/*.o *.o ${DEP} src/main src/interface

# END

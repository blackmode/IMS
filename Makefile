CC = gcc
CFLAGS = -Wall -g

all:	sim

sim.o : sim.c
	${CC} ${CFLAGS} -c sim.c

run:
	./sim

pack:
	zip 02_xslun01_xstefl05.zip Makefile dokumentace.pdf *.h *.c 	

clean:
	rm -f sim
	rm -f sim.o

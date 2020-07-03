PROGS = example
OBJS =

all : ${PROGS}

example : example.c ${OBJS}
	gcc $^ -o $@ ${CFLAGS} -lhiredis

test :
	./example

clean :
	rm -rf ${PROGS} ${OBJS} *~
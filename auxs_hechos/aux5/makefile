CC=gcc
CFLAGS=

ARGS=

all: p1 p2 p3

p1: p1.out
	./$< ${ARGS}

p2: p2.out
	./$< ${ARGS}

p3: p3.out
	./$< ${ARGS}

%: %.c
%: %.o

%.out: %.c
	$(CC)  $(CFLAGS)  $<  -o  $@ 



clean:
	rm -rf *.o *.out

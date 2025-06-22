CC=gcc
CFLAGS=-lm

ARGS=

default:
	@echo "Usage:"
	@echo "	make all         Compile all programs (p1, p2, p3, p4)"
	@echo "	make <p>         Compile <p>.c into <p>.out"
	@echo "	make run-<p>     Compile and run <p>"
	@echo "	make clean       Remove compiled files"

%: %.c
%: %.o

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

run-p3: p3.out
	./p3.out 8

run-%: %.out
	./$*.out $(ARGS)

all: p1 p2 p3 p4

p1: p1.out
p2: p2.out
p3: p3.out
p4: p4.out

clean:
	rm -rf *.o *.out

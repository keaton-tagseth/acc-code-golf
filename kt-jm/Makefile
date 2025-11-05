default: main

main:
	gcc -c main.c -o cg.o

cg: cg.o
	gcc cg.o -o cg -O3

clean:
	-rm -f cg.o
	-rm -f cg
	-rm -f main.o
	-rm -f main
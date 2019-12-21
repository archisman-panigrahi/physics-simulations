all: t.exe

t.exe: try.o
	gcc -o $@ $+ -lm -lcblas -llapacke
clean:
	rm *.exe *.o
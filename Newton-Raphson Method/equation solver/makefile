all: t.exe

t.exe: try.o
	gcc -o $@ $+ -lm -lblas -llapacke
clean:
	rm *.exe *.o
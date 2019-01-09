CC=gcc -Wall

all: testTriangle.exe

testTriangle.exe: testTriangle.o triangle.o
	$(CC) -s -o $@ $+ -lm

clean:
	$(RM) a.out *.exe *.o

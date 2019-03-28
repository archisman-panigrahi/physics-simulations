CC=gcc -Wall

LIBS= -lblas -lm -llapacke

all: jacobian.o triangleRatio.o main.exe NewtonRaphson.o

main.exe: main.o triangleRatio.o jacobian.o NewtonRaphson.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out


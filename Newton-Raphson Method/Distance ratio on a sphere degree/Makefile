CC=gcc -Wall

LIBS= -lcblas -lm -llapacke

all: jacobian.o distanceRatio.o drEarth.exe NewtonRaphson.o

drEarth.exe: drEarth.o distanceRatio.o jacobian.o NewtonRaphson.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out


CC = gcc -Wall

LIBS = -lm -lcblas

all: kapitza_pendulum.exe

kapitza_pendulum.exe: main_invPend.o invPend.o ode.o
	$(CC) -o $@ $+ $(LIBS)
clean:
	rm *.o *.exe
scrub:
	rm *.dat
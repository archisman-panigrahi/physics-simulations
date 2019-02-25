CC = gcc -Wall

LIBS = -lm -lblas

all: motion_of_charge.exe

motion_of_charge.exe: motion_of_charge.o ode.o
	$(CC) -o $@ $+ $(LIBS)
clean:
	rm *.o *.exe
scrub:
	rm *.dat
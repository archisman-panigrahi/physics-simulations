CC = gcc -Wall

LIBS = -lm -lblas

all: motion_of_charge.exe

motion_of_charge.exe: main.o print_motion.o ode.o
	$(CC) -o $@ $+ $(LIBS)
clean:
	rm *.o *.exe
scrub:
	rm *.dat
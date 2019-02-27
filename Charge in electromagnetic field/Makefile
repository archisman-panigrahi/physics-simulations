CC = gcc -Wall

LIBS = -lm -lblas

all: constant_field_motion.exe magnetron_motion.exe

constant_field_motion.exe: main_constant_fields.o print_motion.o ode.o
	$(CC) -o $@ $+ $(LIBS)
magnetron_motion.exe: main_magnetron.o magnetron.o ode.o
	$(CC) -o $@ $+ $(LIBS)
clean:
	rm *.o *.exe
scrub:
	rm *.dat
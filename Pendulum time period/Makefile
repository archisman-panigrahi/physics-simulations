CC=gcc -Wall

LIBS= -lcblas -lm

all: agm.o ellint.o pendulum_RK_time.o time_of_pendulum.exe

time_of_pendulum.exe: print_time.o pendulum_RK_time.o ellint.o agm.o ode.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out

scrub: clean
	$(RM) *.dat

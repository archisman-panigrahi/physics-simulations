CC=gcc -Wall

LIBS= -lblas -lm

all: agm.o ellint.o pendulum_time_period.exe

pendulum_time_period.exe: pendulum_time_period.o ode.o ellint.o agm.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out

scrub: clean
	$(RM) *.dat

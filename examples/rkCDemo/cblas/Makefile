CC=gcc -Wall

LIBS= -lblas -lm

all: msd.exe coupledMassSpring.exe pendulumMotion.exe

msd.exe: msd.o ode.o
	$(CC) -o $@ $+ $(LIBS)

coupledMassSpring.exe: coupledMassSpring.o ode.o
	$(CC) -o $@ $+ $(LIBS)

pendulumMotion.exe: pendulumMotion.o ode.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out

scrub: clean
	$(RM) *.dat

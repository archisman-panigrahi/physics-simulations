CC = gcc -Wall

LIBS = -lm -lblas

all: dhosc.exe

dhosc.exe: main_dhosc.o dhosc.o ode.o random.o
	$(CC) -o $@ $+ $(LIBS)
clean:
	rm *.o *.exe
scrub:
	rm *.dat *.txt *.csv
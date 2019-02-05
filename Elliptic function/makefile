CC = gcc -Wall

LIBS = -lm

all: main.exe Iab.o ellipticfnprinter.exe

Iab.exe: Iab.o
	$(CC) -o $@ $+ $(LIBS)

main.exe: Iab.o main.o
	$(CC) -o $@ $+ $(LIBS)

ellipticfnprinter.exe: Iab.o ellipticfnprinter.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out

scrub:
	$(RM) *.csv
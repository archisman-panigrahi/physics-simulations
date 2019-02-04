CC = gcc -Wall

LIBS = -lm

all: main.exe Iab.o am.o gm.o ellipticfnprinter.exe

Iab.exe: Iab.o am.o gm.o
	$(CC) -o $@ $+ $(LIBS)

main.exe: Iab.o main.o am.o gm.o
	$(CC) -o $@ $+ $(LIBS)

ellipticfnprinter.exe: Iab.o ellipticfnprinter.o am.o gm.o
	$(CC) -o $@ $+ $(LIBS)

am.exe: am.o
	$(CC) -o $@ $+ $(LIBS)

gm.exe: gm.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out

scrub:
	$(RM) *.dat
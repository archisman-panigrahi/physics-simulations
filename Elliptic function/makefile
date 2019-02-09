CC = gcc -Wall

LIBS = -lm
FLAG = -m32

all: main.exe ellint.o ellipticfnprinter.exe agm.o

agm.exe: agm.o
	$(CC) -o $@ $+ $(LIBS)

ellint.exe: ellint.o agm.o
	$(CC) -o $@ $+ $(LIBS)

main.exe: ellint.o main.o agm.o
	$(CC) -o $@ $+ $(LIBS)

ellipticfnprinter.exe: ellint.o ellipticfnprinter.o agm.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out

scrub:
	$(RM) *.csv
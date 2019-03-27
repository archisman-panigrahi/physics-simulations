CC=gcc -Wall

LIBS= -lblas -lm -llapack

all: jacobian.o triangleRatio.o main.exe

main.exe: main.o triangleRatio.o jacobian.o
	$(CC) -o $@ $+ $(LIBS)

clean:
	$(RM) *.o *.exe a.out


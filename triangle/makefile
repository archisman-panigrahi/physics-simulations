
triangle.exe: triangle.o testTriangle.o
	gcc triangle.o testTriangle.o -o triangle.exe -lm

testTriangle.o: testTriangle.c
	gcc -c testTriangle.c

triangle.o: triangle.c triangle.h
	gcc -c triangle.c

clean:
	rm *.o
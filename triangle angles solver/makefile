
triangle: triangle.o testTriangle.o
	gcc triangle.o testTriangle.o -o triangle -lm

testTriangle.o: testTriangle.c
	gcc -c testTriangle.c

triangle.o: triangle.c triangle.h
	gcc -c triangle.c

install:
	cp ./triangle /usr/bin/triangle

clean:
	rm *.o
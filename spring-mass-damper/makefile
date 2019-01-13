
spring_mass_damper:	main.o smd.o
	gcc main.o smd.o -o spring_mass_damper -lm

main.o:	main.c
	gcc -c main.c

smd.o: smd.c
	gcc -c smd.c

install:
	cp ./spring_mass_damper /usr/bin/spring_mass_damper

clean:
	rm *.o *.out
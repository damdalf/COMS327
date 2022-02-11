world: world.o
	gcc world.o -o  world

world.o: world.c map.h
	gcc world.c -Wall -Werror -c
clean:
	rm -f *~ world world.o map.o core

poke: world.o map.o poke327.o
	gcc world.o map.o poke327.o  -o poke
poke327.o: poke327.c
	gcc poke327.c -Wall -Werror -ggdb -c
world.o: world.c map.h
	gcc world.c  -Wall -Werror -ggdb -c
map.o: map.c map.h
	gcc map.c -Wall -Werror -ggdb  -c
clean:
	rm -f *~ poke world.o map.o poke327.o  core

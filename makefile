all: PA6

CFLAGS = -Wall -std=c++11
CFLAGS_DEBUG = -g -O0 -Wall

PA6: Ant.o Cell.o Doodlebug.o Grid.o Organism.o main.o
	g++ $(CFLAGS) main.o Ant.o Cell.o Doodlebug.o Grid.o Organism.o -o PA6

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp
	
Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ $(CFLAGS) -c Doodlebug.cpp

Grid.o: Grid.cpp Grid.h
	g++ $(CFLAGS) -c Grid.cpp

Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp
	
Cell.o: Cell.cpp Cell.h
	g++ $(CFLAGS) -c Cell.cpp

clean:
	rm Ant.o Cell.o Doodlebug.o Grid.o Organism.o main.o PA6




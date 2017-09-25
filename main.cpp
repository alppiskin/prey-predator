// main.cpp -- ALP PISKIN & ANKIT KOTWAL


#include "Grid.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char* argv[]) {

	if (argc > 7) {
		std::cout << "Error: Invalid Input\n";
		exit(0);
	}

	srand(1);

	unsigned gridSize = 20;
	unsigned numDoodles = 5;
	unsigned numAnts = 100;
	unsigned steps = 1000;
	unsigned pause = 1;

	if (argc >= 2) {
		gridSize = atoi(argv[1]);
	}

	if (argc >= 3) {
		numDoodles = atoi(argv[2]);
	}

	if (argc >= 4) {
		numAnts = atoi(argv[3]);
	}

	if (argc >= 5) {
		steps = atoi(argv[4]);
	}

	if (argc >= 6) {
		int seed = atoi(argv[5]);
		srand(seed);
	}

	if (argc >= 7) {
		pause = atoi(argv[6]);
	}

	Grid *a = new Grid(gridSize,gridSize);

	if(!a->loadGrid(numAnts, numDoodles)){
		std::cout << "Number of ants and doodles are greater than the board size..." << std::endl;
		return 1;
	}

	std::cout << " -- Initial State: " << std::endl;
	a->printGrid();

	for (unsigned i = 0; i < steps; i++) {
		a->run();
		if (i % pause == 0) {
			a->printGrid();
			std::cout << "----------------------------------\n -- Step:" << i+1 << std::endl;
		}
	}

	std::cout << " -- End State: " << std::endl;
	a->printGrid();

	return 0;
}

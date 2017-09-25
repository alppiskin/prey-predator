// Grid.h -- ALP PISKIN & ANKIT KOTWAL


#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Cell.h"

class Cell;

using std::vector;

class Grid {
public:
	Grid();
	Grid(unsigned width, unsigned height);

	bool loadGrid(float spawn_chace);
	bool loadGrid(unsigned numAnts, unsigned numDoodlebugs);

	void printGrid();

	vector< vector<Cell*> > getData();


	unsigned getHeight();
	unsigned getWidth();

	void run();

	virtual ~Grid();
private:
	vector< vector<Cell*> > data;
	unsigned height = 20;
	unsigned width = 20;
};

#endif /* GRID_H_ */

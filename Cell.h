// Cell.h -- ALP PISKIN & ANKIT KOTWAL


#ifndef CELL_H_
#define CELL_H_

#include "Organism.h"
#include "Grid.h"
#include <vector>

class Grid;

using std::vector;

class Organism;

class Cell {
public:
	Cell(unsigned x, unsigned y, Grid* grid);
	Organism* getOrganism();
	void setOrganism(Organism* org);
	virtual ~Cell();
	vector<Cell*> getAdjacent();

	unsigned getX();
	unsigned getY();
	Grid* getGrid();

private:
	Organism* organism;
	unsigned x;
	unsigned y;
	Grid *grid;
};

#endif /* CELL_H_ */

// Organism.h -- ALP PISKIN & ANKIT KOTWAL


#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <iostream>
#include "Cell.h"

class Cell;

class Organism {
public:
	Organism();
	virtual void move() = 0;
	virtual void breed() = 0;
	virtual ~Organism();
	virtual std::string getType() = 0;
	void setCell(Cell* to_set);
	Cell* getCell();
private:
	Cell* current;
};

#endif /* ORGANISM_H_ */

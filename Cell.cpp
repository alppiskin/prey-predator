// Cell.cpp -- ALP PISKIN & ANKIT KOTWAL

#include "Cell.h"
#include <vector>
#include <cstdlib>

using std::vector;

Cell::Cell(unsigned x, unsigned y, Grid* grid) {
	organism = NULL;
	this->x = x;
	this->y = y;
	this->grid = grid;
}

Organism* Cell::getOrganism() {
	return organism;
}

void Cell::setOrganism(Organism* org) {
	if (org != NULL) {
		org->setCell(this);
	}
	organism = org;
}

Cell::~Cell() {

}

unsigned Cell::getX(){return x;}
unsigned Cell::getY(){return y;}
Grid* Cell::getGrid(){return grid;}

vector<Cell*> Cell::getAdjacent(){
	std::vector<Cell*> cell;
	int left = x - 1;
	int right = x + 1;
	int up = y - 1;
	int down = y + 1;

	if(left > -1){
		cell.push_back(grid->getData()[left][y]);
	}

	if(right < (int)grid->getWidth()){
		cell.push_back(grid->getData()[right][y]);
	}

	if(down < (int)grid->getHeight()){
		cell.push_back(grid->getData()[x][down]);
	}

	if(up > -1){
		cell.push_back(grid->getData()[x][up]);
	}

	return cell;

}

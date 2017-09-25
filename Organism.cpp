// Organism.cpp -- ALP PISKIN & ANKIT KOTWAL


#include "Organism.h"

Organism::Organism() {

}

Organism::~Organism() {
}

void Organism::setCell(Cell* to_set){
	this->current = to_set;
}

Cell* Organism::getCell(){
	return current;
}

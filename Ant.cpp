// Ant.cpp -- ALP PISKIN & ANKIT KOTWAL

#include "Ant.h"

Ant::Ant() {

}

Ant::~Ant() {

}

void Ant::move(){
	Cell* c = this->getCell();
	vector<Cell*> cells = getCell()->getAdjacent();

	bool can_move = false;

	for (unsigned i = 0; i < cells.size(); i++) {
		if(cells[i]->getOrganism() == NULL){can_move = true;}
	}

	while(can_move){
		int x = 0;
		int y = 0;

		if(rand()%2){
			x = rand()%2 ? -1 : 1;
		} else {
			y = rand()%2 ? -1 : 1;
		}

		int new_x = c->getX() + x;
		int new_y = c->getY() + y;

		if ((new_x >=0 && new_x < (int)c->getGrid()->getWidth()) && (new_y >=0 && new_y < (int)c->getGrid()->getHeight())) {
			if (c->getGrid()->getData()[new_x][new_y]->getOrganism() == NULL) {
				c->getGrid()->getData()[new_x][new_y]->setOrganism(this);
				c->setOrganism(NULL);
				break;
			}
		}

	}

	if (move_count >= 3) {
		breed();
	}

	move_count++;
}

void Ant::breed(){
	bool can_breed = false;

	vector<Cell*> cells = getCell()->getAdjacent();
	for (unsigned i = 0; i < cells.size(); i++) {
		if(cells[i]->getOrganism() == NULL){can_breed = true;}
	}

	if (can_breed) {
		unsigned i = 0;
		while (true) {
			float r = float(rand()) / float(RAND_MAX);
			float chance = 1.0/float(cells.size());
			if(r > chance){
				if(cells[i]->getOrganism() == NULL){
					move_count = 0;
					cells[i]->setOrganism(new Ant());
					break;
				}
			}
			i++;
			if (i >= cells.size()) {
				i = 0;
			}
		}
	}
}

std::string Ant::getType(){
	return "Ant";
}

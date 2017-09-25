// Doodlebug.cpp -- ALP PISKIN & ANKIT KOTWAL


#include "Doodlebug.h"

Doodlebug::Doodlebug() {

}

Doodlebug::~Doodlebug() {

}

void Doodlebug::move() {

	if (starved >= 3) {
		Cell* c = this->getCell();
		c->setOrganism(NULL);
		delete this;
		return;
	}

	bool eaten = false;
	Cell* c = this->getCell();
	vector<Cell*> cells = getCell()->getAdjacent();

	vector<Cell*> ant_cells;
	for (unsigned i = 0; i < cells.size(); i++) {
		if(cells[i]->getOrganism() != NULL)
			if (cells[i]->getOrganism()->getType().compare(Ant().getType()) == 0) {
				ant_cells.push_back(cells[i]);
			}
	}

	unsigned i = 0;
	while (!eaten && ant_cells.size() > 0) {
		float r = float(rand()) / float(RAND_MAX);
		float chance = 1.0/float(ant_cells.size());
		if ( r < chance ) {
			Organism* a = c->getGrid()->getData()[ant_cells[i]->getX()][ant_cells[i]->getY()]->getOrganism();
			c->getGrid()->getData()[ant_cells[i]->getX()][ant_cells[i]->getY()]->setOrganism(this);
			c->getGrid()->getData()[c->getX()][c->getY()]->setOrganism(NULL);
			delete a;
			eaten = true;
			break;
		}
		i++;
		if (i >= ant_cells.size()) {
			i = 0;
		}
	}

	if (eaten) {
		starved = 0;
	} else {
		starved++;
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

	}

	if (move_count >= 8) {
		breed();
	}

	move_count++;
}

void Doodlebug::breed() {
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
					cells[i]->setOrganism(new Doodlebug());
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

std::string Doodlebug::getType(){
	return "Doodlebug";
}

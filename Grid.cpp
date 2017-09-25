// Grid.cpp -- ALP PISKIN & ANKIT KOTWAL

#include "Cell.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::vector;

vector< vector<Cell*> > createCells2d(unsigned width, unsigned height, Grid* actual) {
	vector< vector<Cell*> > grid;
	for(unsigned i = 0; i < height; i++) {
		vector<Cell*> cells;
		grid.push_back(cells);
		for(unsigned k = 0; k < width; k++) {
			Cell *a = new Cell(i, k, actual);
			grid[i].push_back(a);
		}
	}
	return grid;
}

Grid::Grid() {
	data = createCells2d(width, height, this);
}


Grid::Grid(unsigned width, unsigned height) {
	this->width = width;
	this->height = height;
	data = createCells2d(width, height, this);
}
/*
struct Index {
	unsigned int width;
	unsigned int height;
};*/

bool Grid::loadGrid(float spawn_rate) {

	return true;
}

bool Grid::loadGrid(unsigned numAnts, unsigned numDoodlebugs)  {
	unsigned total = numAnts + numDoodlebugs;
	unsigned grid_size = width * height;

	if(total > grid_size) return false;

	for (unsigned i = 0; i < numAnts; i++) {
		bool placed = false;
		while(!placed){
			unsigned x = rand() % width;
			unsigned y = rand() % height;

			if (data[x][y]->getOrganism() == NULL) {
				Organism *to_set = new Ant();
				data[x][y]->setOrganism(to_set);
				placed = true;
			}

		}
	}

	for (unsigned i = 0; i < numDoodlebugs; i++) {
		bool placed = false;
		while(!placed){
			unsigned x = rand() % width;
			unsigned y = rand() % height;

			if (data[x][y]->getOrganism() == NULL) {
				Organism *to_set = new Doodlebug();
				data[x][y]->setOrganism(to_set);
				placed = true;
			}

		}
	}

	return true;
}

void Grid::printGrid() {
	cout << "----------------------------------\n";

	for(unsigned k = 0; k < height; k++){
		for(unsigned i = 0; i < width; i++){
			Organism* ptr = data[i][k]->getOrganism();
			if(ptr != NULL){
				if (ptr->getType().compare(Ant().getType()) == 0) {
					cout << "\033[0;31mo \033[0m";
				} else if (ptr->getType().compare(Doodlebug().getType()) == 0) {
					cout << "\033[1;32mx \033[0m";
				}
			} else {
				cout << "  ";
			}
		}
		cout << "\n";
	}
}

Grid::~Grid() {

}

vector< vector<Cell*> > Grid::getData(){
	return data;
}

unsigned Grid::getHeight(){
	return height;
}

unsigned Grid::getWidth(){
	return width;
}

void Grid::run(){
	vector<Organism*> to_move;
	for(unsigned k = 0; k < height; k++){
		for(unsigned i = 0; i < width; i++){
			Organism* ptr = data[i][k]->getOrganism();
			if(ptr != NULL){
				if (ptr->getType().compare(Doodlebug().getType()) == 0) {
					to_move.push_back(ptr);
				}
			} else {

			}
		}
	}
	for(unsigned i = 0; i < to_move.size(); i++){
		to_move[i]->move();
	}
	to_move.clear();

	for(unsigned k = 0; k < height; k++){
		for(unsigned i = 0; i < width; i++){
			Organism* ptr = data[i][k]->getOrganism();
			if(ptr != NULL){
				if (ptr->getType().compare(Ant().getType()) == 0) {
					to_move.push_back(ptr);
				}
			} else {

			}
		}
	}
	for(unsigned i = 0; i < to_move.size(); i++){
		to_move[i]->move();
	}
}


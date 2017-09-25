// Doodlebug.h -- ALP PISKIN & ANKIT KOTWAL


#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Ant.h"

class Doodlebug: public Organism {
public:
	Doodlebug();
	void move();
	void breed();
	std::string getType();
	virtual ~Doodlebug();
private:
	unsigned starved = 0;
	unsigned move_count = 0;
};

#endif /* DOODLEBUG_H_ */

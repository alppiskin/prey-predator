// Ant.h -- ALP PISKIN & ANKIT KOTWAL


#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant: public Organism {
public:
	Ant();
	void move();
	void breed();
	std::string getType();
	virtual ~Ant();
private:
	unsigned move_count = 0;
};

#endif /* ANT_H_ */

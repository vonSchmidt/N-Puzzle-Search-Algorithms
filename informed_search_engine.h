#ifndef INF_H
#define INF_H
#include "search_engine.h"
#include <iostream>
#include "heuristic.h"

class informed_search_engine
	: public search_engine {
protected:
    heuristic *h;
public:
	virtual void search(state* init, state* goal, state*& solution);
    heuristic *get_heuristic();
    void set_heuristic(heuristic *);
};
#endif // INF_H

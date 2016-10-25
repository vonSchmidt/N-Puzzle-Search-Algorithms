#ifndef UNINF_H
#define UNINF_H
#include "search_engine.h"
#include <iostream>
#include "state.h"
class uninformed_search_engine
	: public search_engine {

public:
	virtual void search(state *init, state *goal, state *&solution);

};
#endif // UNINF_H

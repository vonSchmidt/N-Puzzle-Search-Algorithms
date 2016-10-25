#pragma once
#include "state.h"
#include "container.h"
#include <set>
using namespace std;
class search_engine {
public:
	search_engine();
	virtual ~search_engine(){ delete this->closed; };
    virtual void search(state *, state *, state *&)=0;
    int get_fringe_size() { return this->fringe->size(); }
    int get_closed_size() { return this->closed->size(); }
    int get_iterations();

protected:
    container<state *> *fringe;
    set<hash_id> *closed;
    int iterations;

};

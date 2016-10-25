#include "uninformed_search_engine.h"
#include "priority_queue_adaptor.hpp"
#include "state_ordering.hpp"

class uniform_cost_search:public uninformed_search_engine{

public :
    uniform_cost_search(){
        this->fringe = new priority_queue_adaptor<state *, dijkstra_ordering>();
    }
    ~uniform_cost_search(){
        delete this->fringe;
    }

};

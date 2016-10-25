#include "informed_search_engine.h"
#include "priority_queue_adaptor.hpp"
#include "state_ordering.hpp"
#include "heuristic.h"
class astar_search
    :public informed_search_engine{
public :
    astar_search(){
        this->fringe = new priority_queue_adaptor<state *, astar_ordering>();
    }

    ~astar_search(){
        delete this->fringe;
    }
};

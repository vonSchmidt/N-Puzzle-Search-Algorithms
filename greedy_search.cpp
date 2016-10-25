#include "informed_search_engine.h"
#include "priority_queue_adaptor.hpp"
#include "state_ordering.hpp"

class greedy_search:public informed_search_engine{
public :
    greedy_search(){
        this->fringe = new priority_queue_adaptor<state *, greedy_ordering>();
    }
    ~greedy_search(){
        delete this->fringe;
    }
};

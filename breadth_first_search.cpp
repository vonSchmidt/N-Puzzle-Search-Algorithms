#include "uninformed_search_engine.h"
#include "queue_adaptor.hpp"
class breadth_first_search:public uninformed_search_engine{




public :
    breadth_first_search(){
        this->fringe = new queue_adaptor<state *>();
    }
    ~breadth_first_search(){
        delete this->fringe;
    }

};

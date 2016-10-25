#include "uninformed_search_engine.h"
#include "stack_adaptor.hpp"
class depth_first_search:public uninformed_search_engine{




public :
    depth_first_search(){
        this->fringe = new stack_adaptor<state *>();
    }
    ~depth_first_search(){
        delete this->fringe;
    }

};

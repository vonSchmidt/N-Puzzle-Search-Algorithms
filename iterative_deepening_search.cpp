#ifndef IDS_H
#define IDS_H
#include "uninformed_search_engine.h"
#include "depth_limited_search.cpp"
#include "stack_adaptor.hpp"
class iterative_deepening_search
        : public uninformed_search_engine {
private:

public:
    iterative_deepening_search() {};

    ~iterative_deepening_search() {
        delete this->fringe;
    };

    void search(state *init, state *goal, state *&solution) {
        int depth = 0;
        depth_limited_search *s;
        while(!solution){
            cout<<"Using depth = "<<depth<<endl;
            s = new depth_limited_search(depth);
            s->search(init, goal, solution);
            depth++;
        }
    }

};


#endif // IDS_H


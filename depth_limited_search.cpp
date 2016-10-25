#ifndef DLS_H
#define DLS_H
#include "uninformed_search_engine.h"
#include "stack_adaptor.hpp"
class depth_limited_search
        : public uninformed_search_engine {
private:
    int limit;

public:
    depth_limited_search(int limit) {
        this->limit = limit;
        this->fringe = new stack_adaptor<state *>();
    };

    ~depth_limited_search() {
        delete this->fringe;
    };

    void search(state *init, state *goal, state *&solution) {
        state *temp;
        int i;
        int iter = 0;
        vector<state *> children;
        //push the initial state
        this->fringe->push(init);
        while(this->fringe->size()) {
            temp = fringe->top();
            cout << "\r" << ++iter << " iterations";
            this->fringe->pop();

            if(temp->get_state_id() == goal->get_state_id()) {
                solution = temp;
                this->iterations = iter;
                cout << endl;
                return;
            }
            //if limit dont expand;

            if (temp->get_g() == this->limit) continue;
            children = temp->expand();
            for(i = 0; i < 4; i++)
                if (children[i])
                    this->fringe->push(children[i]);

        }
        this->iterations = iter;
        cout << endl;
    }

};


#endif // DLS_H

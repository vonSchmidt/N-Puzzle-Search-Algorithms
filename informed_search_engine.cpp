#include "informed_search_engine.h"

heuristic *informed_search_engine::get_heuristic(){
    return this->h;
}
void informed_search_engine::set_heuristic(heuristic *h){
    this->h = h;
}



void informed_search_engine::search(state* init, state* goal, state*& solution) {
     // no heuristic specified! HACKER HACKER!
    if (!this->h) return;
    state *temp;
    int i;
    int iter = 0;
    vector<state *> children;
    //push the initial state
    this->fringe->push(init);
    while(this->fringe->size()){
        temp = fringe->top();
        cout << "\r" << ++iter << " iterations";
        this->fringe->pop();
        if(temp->get_state_id() == goal->get_state_id()){
            solution = temp;
            this->iterations = iter;
            cout << endl;
            return;
        }
        if(this->closed->find(temp->get_state_id())==this->closed->end()) {
            //if not found
            children = temp->expand();
            this->closed->insert(temp->get_state_id());

            for(i = 0; i < 4; i++)
                if (children[i]) {
                        children[i]->set_h(this->h->get_heuristic(children[i]));
                        this->fringe->push(children[i]);
                    }
        }
    }
    this->iterations = iter;
    cout << endl;
}



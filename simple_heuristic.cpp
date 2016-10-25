#include "simple_heuristic.h"
simple_heuristic::simple_heuristic(state *goal)
    : heuristic(goal) {}

int simple_heuristic::get_heuristic(state *temp) {
    int h = 0;
    small_integer *tab1 = temp->get_data();
    small_integer *tab2 = this->goal_s->get_data();
    int i;
    for(i=0; i < state::get_size(); i++)
        if(tab1[i] != tab2[i])
            h++;
    return h;
}
simple_heuristic::~simple_heuristic() {}

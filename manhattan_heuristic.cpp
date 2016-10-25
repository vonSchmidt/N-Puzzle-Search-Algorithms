#include <cmath>
#include "manhattan_heuristic.h"

manhattan_heuristic::manhattan_heuristic(state *goal)
    : heuristic(goal) {}

int manhattan_heuristic::get_heuristic(state *temp) {
    int h = 0;
    small_integer *tab1 = temp->get_data();
    small_integer *tab2 = this->goal_s->get_data();
    int i, j;
    int i1, i2, j1, j2; // needed for manhattan distance, see below.
    int num;
    for(i=0; i < state::get_size(); i++) {
        num = tab1[i];
        for (j = 0; j < state::get_size(); j++)
            if (tab2[j] == num)
                break;
        // j now contains the position of num in tab2
        // let i1, i2 be the coordinates of num in tab1
        // and j1, j2 be the coordinates of num in tab2
        i1 = i / state::get_side();
        i2 = i % state::get_side();
        j1 = j / state::get_side();
        j2 = j % state::get_side();
        h += std::abs(i1 - j1) + std::abs(i2 - j2);
    }

    return h;
}
manhattan_heuristic::~manhattan_heuristic() {}


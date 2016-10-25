#ifndef STATE_ORD_H
#define STATE_ORD_H
#include "state.h"

class dijkstra_ordering {
public:
    bool operator() (state *s1, state *s2){
        return s1->get_g() > s2->get_g();
    }
};

class greedy_ordering {
public:
    bool operator() (state *s1, state *s2){
        return s1->get_h() > s2->get_h();
    }
};

class astar_ordering {
public:
    bool operator() (state *s1, state *s2){
        return s1->get_g() + s1->get_h()
            > s2->get_g() + s2->get_h();
    }
};
#endif // STATE_ORD_H

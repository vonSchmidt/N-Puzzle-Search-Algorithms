#ifndef HEURISTIC_H
#define HEURISTIC_H
#include "state.h"
class heuristic {
protected:
    state *goal_s;
public:
    heuristic(state *goal);
    virtual ~heuristic() {};
    virtual int get_heuristic(state *init) = 0;
};

#endif /* HEURISTIC_H */

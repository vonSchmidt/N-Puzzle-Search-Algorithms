#ifndef SIMPLE_H
#define SIMPLE_H
#include "state.h"
#include "heuristic.h"
class simple_heuristic
        : public heuristic {

public:
    simple_heuristic(state *goal);
    ~simple_heuristic();
    int get_heuristic(state *);
};
#endif /* SIMPLE_H */

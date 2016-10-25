#ifndef MANHATTAN_H
#define MANHATTAN_H
#include "state.h"
#include "heuristic.h"
class manhattan_heuristic
        : public heuristic {

public:
    manhattan_heuristic(state *goal);
    ~manhattan_heuristic();
    int get_heuristic(state *);
};
#endif /* MANHATTAN_H */



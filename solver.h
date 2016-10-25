#pragma once
#include <string>
#include "search_engine.h"
#include "state.h"
#include <ctime>

using namespace std;

typedef state solution;

class solver {
private:
    clock_t start_time;
    clock_t end_time;
    state *init;
    state *goal;
    solution *s;
    search_engine *engine;
    small_integer problem_size;

public:
	solver();
	~solver();
    state *get_init();
    state *get_goal();
	search_engine *get_engine();

	void set_init(state *);
    void set_goal(state *);
	void set_engine(search_engine *);

    bool read_problem(string="input.txt");
    void run_search();
    void write_solution(string="output.txt");
    bool is_solvable();
};

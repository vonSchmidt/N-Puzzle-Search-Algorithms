#include "solver.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

solver::solver() {}

solver::~solver() {
    delete this->engine;
    delete this->init;
    delete this->goal;
    delete this->s;
}

state* solver::get_init() {
    return this->init;
}

state* solver::get_goal() {
    return this->goal;
}

search_engine* solver::get_engine() {
    return this->engine;
}

void solver::set_init(state* init) {
    this->init = init;
}

void solver::set_goal(state* goal) {
    this->goal = goal;
}

void solver::set_engine(search_engine* engine) {
    this->engine = engine;
}

bool solver::read_problem(string path) {
    try {
        ifstream input;
        input.open(path);
        if (!input.is_open()) throw exception();
        cout << "Reading Problem from ``" << path << "``" << endl;
        input >> this->problem_size;
        state::set_size(this->problem_size);
        int i;
        small_integer *temp1 = new small_integer[this->problem_size + 1];
        small_integer *temp2 = new small_integer[this->problem_size + 1];
        for (i = 0; i < state::state_size + 1; i++)
            input >> temp1[i];

        for (i = 0; i < state::state_size + 1; i++)
            input >> temp2[i];

        this->init = new state();
        this->init->set_data(temp1);

        this->goal = new state();
        this->goal->set_data(temp2);
        input.close();
        return true;
	} catch (...) {
		cout << "Input Error." << endl;
	}
	return false;
}

void solver::run_search() {
    if (this->init && this->goal) {
        this->start_time = clock();
		if (this->is_solvable())
			this->engine->search(this->init, this->goal, this->s);
		else cout << "Unsolvable Puzzle configuration." << endl;
        this->end_time = clock();
    } else {
        cout << "Invoked search method before reading problem!" << endl;
    }
}

void solver::write_solution(string path) {
    try {
        ofstream output;
        if (!s) {
            cout << "No Solution." << endl;
        } else {
            output.open(path);
            if (!output.is_open()) throw exception();
            state *temp = this->s;
            s->print(output);
            while (temp->get_parent()) {
                output << temp->get_parent()->get_action() << endl;
                temp->get_parent()->print(output);
                temp = temp->get_parent();
            }
            output << "Total Cost: " << s->get_g() << " steps." << endl;
            cout << "Total Cost: " << s->get_g() << " steps." << endl;
        }
        // Time
        output << "Total Time: " << double(end_time - start_time) / CLOCKS_PER_SEC
             << " seconds." << endl;
		cout << "Total Time: " << double(end_time - start_time) / CLOCKS_PER_SEC
             << " seconds." << endl;
        // Memory
        output << "Total Memory: " <<
             (engine->get_closed_size() + engine->get_fringe_size())
             * sizeof(state) << " Bytes." << endl;
		cout << "Total Memory: " <<
             (engine->get_closed_size() + engine->get_fringe_size())
             * sizeof(state) << " Bytes." << endl;
        //Iterations
        output << "Total Iterations: " << this->get_engine()->get_iterations() <<" iterations." << endl;
		cout << "Total Iterations: " << this->get_engine()->get_iterations() <<" iterations." << endl;
        output.close();
        cout << "Writing Completed Successfully." << endl;
    }
    catch (...) {
        cout << "Output Error." << endl;
    }
}

int get_index(small_integer *arr, int n, small_integer size_puzzle) {
	int i;
	for(i = 0; i < state::get_size() + 1; i++)
		if(arr[i] == n)
			return i;
	return -1;
}
bool solver::is_solvable() {
	if (!this->init || !this->goal) {
		cout << "Called solvability check without feeding input." << endl;
		return false;
	}
	int parity = 0;
	int gridWidth = state::get_side();
	int row = 0; // the current row we are on
	int blankRow = 0; // the row with the blank tile

	for (int i = 0; i < state::get_size() + 1; i++) {
		if (i % gridWidth == 0) { // advance to next row
			row++;
		}
		if (this->init->get_data()[i] == 0) { // the blank tile
			blankRow = row; // save the row on which encountered
			continue;
		}
		for (int j = i + 1; j < state::get_size() + 1; j++) {
			if (get_index(this->goal->get_data(), this->init->get_data()[i], state::get_size() + 1)
				> get_index(this->goal->get_data(), this->init->get_data()[j], state::get_size() + 1)
					&& this->init->get_data()[j] != 0) {
				parity++;
			}
		}
	}
	if (gridWidth % 2 == 0) { // even grid
		if (blankRow % 2 == 0) { // blank on odd row; counting from bottom
			return parity % 2 == 0;
		} else { // blank on even row; counting from bottom
			return parity % 2 != 0;
		}
	} else { // odd grid
		return parity % 2 == 0;
	}
}

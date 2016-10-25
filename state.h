#pragma once
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#define INF 9999
using namespace std;

typedef unsigned short small_integer;
typedef unsigned int hash_id;
enum state_action {UP, DOWN, LEFT, RIGHT};
class state {
public:
    static small_integer state_size;		// The Problem Size N as in N-Puzzle
    static small_integer side;				// The square Puzzle side units length
	state();
	state(const state&);                    // Copy Constructor
	~state();
	// Getters
	hash_id get_state_id();
	small_integer *get_data();
    static small_integer get_size();
	small_integer get_gap_pos();
	pair<small_integer, small_integer> get_gap_coord();
	int get_g();
	int get_h();
	static small_integer get_side();
	state *get_parent();
	string get_action();
	// Setters
	void set_data(small_integer *);
	static void set_size(small_integer);
	void set_gap_pos(small_integer);
	void set_gap_coord(int, int);
	void set_g(int);
	void set_h(int);
	void set_action(state_action);
	void set_parent(state *);
	string to_str();
 	void print(ostream& = cout);
	hash_id hash_state();
	vector<state *>expand();

private:
	hash_id state_id;			// A positive 32-bit unique identifier
	small_integer *data;		// The State Data numbers
	small_integer gap;			// Position of the Gap in the Puzzle
	int g;
	int h;						// g: The path cost up to the This state
	state *parent;				// A reference to the predecessor of this state
	state_action action;				// An action from the predecessor to this state
};

#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <string>
#include <sstream>
#include "state.h"

using namespace std;

small_integer state::state_size = 0;
small_integer state::side = 0;

state::state() {
	this->data		= NULL;
	this->gap		= 0;
	this->g			= 0;
	this->h			= INF;
	this->state_id	= 0;

}

state::state(const state &s){
    this->gap=s.gap;
    int i = 0;
    this->data = new small_integer [state::state_size];
    for(; i < state::state_size + 1; i++){
        this->data[i] = s.data[i];
        cout << "HERE\n";
        cout<<s.data[i]<<endl;
        cout<<this->data[i]<<endl;

    }
    this->h = INF;
    this->state_id=0;

}

state::~state() {
	delete [] this->data;
	delete parent;
}

hash_id state::get_state_id() {
	return (this->state_id == 0)?
		this->hash_state()
		:this->state_id;
}

small_integer *state::get_data() {
	return this->data;
}

state* state::get_parent() {
	return this->parent;
}

string state::get_action() {
    switch(this->action) {
    case UP:
        return "UP";
    case DOWN:
        return "DOWN";
    case LEFT:
        return "LEFT";
    case RIGHT:
        return "RIGHT";
    default:
        return "HACKER!! HACKER!!!! :(";
    }
}

small_integer state::get_size() {
	return state_size;
}

small_integer state::get_gap_pos() {
	return this->gap;
}

pair<small_integer, small_integer> state::get_gap_coord() {
	return pair<small_integer, small_integer> (
	           this->gap / state::side,
	           this->gap % state::side
	       );
}

int state::get_g() {
	return this->g;
}

small_integer state::get_side() {
	return state::side;
}

void state::set_data(small_integer *data) {
	this->data = data;
	int i = 0;
	for (; i < state_size + 1; i++)
		if (this->data[i] == 0)
			break;
	this->gap = i;
}

void state::set_size(small_integer state_size) {
	state::state_size = state_size;
	state::side = floor(sqrt(state_size + 1));
}

void state::set_gap_pos(small_integer gap) {
	this->gap = gap;
}

void state::set_gap_coord(int i, int j) {
	this->gap = state::state_size * i + j;
}

void state::set_g(int g) {
	this->g = g;
}

string state::to_str() {
	stringstream out;
	int i;
	for (i = 0; i < state_size + 1; i++)
		out << this->data[i];
	return out.str();
}

void state::print(ostream &out) {
	int i, j;
	int side = floor(sqrt(state_size + 1));
	for (i = 0; i < state_size + 1;) {
		out << " |";
		for (j = 0; j < side; j++) {
			if (this->data[i] == 0)
				out << setw(3) << " ";
			else
				out << setw(3) << this->data[i];
			i++;
		}
		out << " |" << endl;
	}
	out << endl;
}

unsigned int state::hash_state() {
	hash<string> hash_function;
	return (this->state_id = hash_function(this->to_str()));
}

void swap_elements(small_integer &a, small_integer &b){
    int temp = a;
    a = b;
    b = temp;
}

state* state_generator(state *s, int delta_i, int delta_j ){
    pair<small_integer, small_integer> gap = s->get_gap_coord();
    small_integer old_i = gap.first;
    small_integer old_j = gap.second;
    int new_i = old_i + delta_i;
    int new_j = old_j + delta_j;

    if(new_i < 0 || new_i >= state::side)
        return NULL;
    if(new_j < 0 || new_j >= state::side)
        return NULL;

    state *new_state = new state();
    new_state->set_gap_pos(s->get_gap_pos());
    small_integer *temp = new small_integer [state::state_size];
    // g and h and id
    for (int i = 0; i < state::state_size + 1; i++)
        temp[i] = s->get_data()[i];

	swap_elements(
		temp[s->get_gap_pos()],
		temp[new_i * state::side + new_j]
	);

//	small_integer t = temp[s->get_gap_pos()];
//	temp[s->get_gap_pos()] = temp[new_i * state::side + new_j];
//	temp[new_i * state::side + new_j] = t;

	new_state->set_data(temp);
	new_state->set_g(s->get_g() + 1); // unit cost per action
	new_state->set_parent(s);
	if (delta_i < 0)
		new_state->set_action(UP);
	if (delta_i > 0)
		new_state->set_action(DOWN);
	if (delta_j < 0)
		new_state->set_action(LEFT);
	if (delta_j > 0)
		new_state->set_action(RIGHT);

    return new_state;
}

vector<state *>state::expand(){
    vector<state *> children;
    children.push_back(state_generator(this, -1, 0));
    children.push_back(state_generator(this, +1, 0));
    children.push_back(state_generator(this, 0, -1));
    children.push_back(state_generator(this, 0, +1));
    return children;
}

void state::set_action(state_action action) {
	this->action = action;
}

void state::set_parent(state *s) {
	this->parent = s;
}
int state::get_h() {
    return this->h;
}
void state::set_h(int h){
    this->h = h;
}



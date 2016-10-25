#include "search_engine.h"
search_engine::search_engine() {
	this->iterations = 0;
    this->closed = new set<hash_id>();
}

int search_engine::get_iterations(){
    return this->iterations;
}


#include <iostream>
#include <string>
#include <getopt.h>
#include "solver.h"

#include "breadth_first_search.cpp"
#include "depth_first_search.cpp"
#include "uniform_cost_search.cpp"
#include "depth_limited_search.cpp"
#include "iterative_deepening_search.cpp"
#include "greedy_search.cpp"
#include "astar_search.cpp"

#include "simple_heuristic.h"
#include "manhattan_heuristic.h"

using namespace std;

int main(int argc, char **argv) {
	string 	engine = "",
			heuristic = "",
			input = "input.txt",
			output = "output.txt";
	search_engine *search;
	int c;
	int option_index = 0;
	while(1) {
		static struct option long_options[] = {
			{"help",     		no_argument, 		0,  'h' },
			{"search",     		required_argument, 	0,  's' },
			{"heuristic",     	required_argument, 	0,  'e' },
			{"in",	     		required_argument, 	0,  'i' },
			{"out",     		required_argument, 	0,  'o' }
		};

		c = getopt_long(argc, argv, "",
			long_options, &option_index);
		if (c == -1) break;

		switch(c) {
		case 's':
			engine = string(optarg);
			break;
		case 'e':
			heuristic = string(optarg);
			break;
		case 'i':
			input = string(optarg);
			break;
		case 'o':
			output = string(optarg);
		case '?':
			break;
		case 'h':
			cout << "Usage: " << argv[0] << endl;
			cout << "\t" << "--help\t\tDISPLAY HELP MESSAGE" << endl;
			cout << endl;
			cout << "\t" << "--search\tSEARCH ENGINE" << endl;
			cout << "\t\t\t * BFS\t\tBreadth First Search" << endl;
			cout << "\t\t\t * DFS\t\tDepth First Search" << endl;
			cout << "\t\t\t * DLS\t\tDepth Limited Search" << endl;
			cout << "\t\t\t * IDS\t\tIterative Deepening Search" << endl;
			cout << "\t\t\t * UCS\t\tUniform Cost Search" << endl;
			cout << "\t\t\t * GREEDY\tGreedy Best First Search" << endl;
			cout << "\t\t\t * ASTAR\tA-Star Best First Search" << endl;
			cout << endl;
			cout << "\t" << "--heuristic\tHEURISTIC FUNCTION" << endl;
			cout << "\t\t\t * SIMPLE\tSimple Misplaced Tile Heuristic" << endl;
			cout << "\t\t\t * MANHATTAN\tManhattan Distance Heuristic" << endl;
			cout << endl;
			cout << "\t" << "--in\t\tREADS FROM FILE, DEFAULT = `input.txt`" << endl;
			cout << "\t" << "--out\t\tWRITES TO FILE, DEFAULT = `output.txt`" << endl;
			exit(EXIT_SUCCESS);
		default:
			cout << "Wrong usage. Use --help to get help." << endl;
			exit(EXIT_FAILURE);
		}
	}

	if (optind < argc || argc < 3) {
		cout << "Wrong usage. Use --help to get help." << endl;
		exit(EXIT_FAILURE);
	}

	if (engine == "BFS")
		search = new breadth_first_search();
	else if (engine == "DFS")
		search = new depth_first_search();
	else if (engine == "DLS") {
		int depth;
		cout << "Input max depth of DLS Algorithm: ";
		cin >> depth;
		search = new depth_limited_search(depth);
		cout << endl;
	}
	else if (engine == "IDS")
		search = new iterative_deepening_search();
	else if (engine == "UCS")
		search = new uniform_cost_search();
	else if (engine == "GREEDY")
		search = new greedy_search();
	else if (engine == "ASTAR")
		search = new astar_search();
	else {
		cout << "Wrong Search usage. Use --help to get help." << endl;
		exit(EXIT_FAILURE);
	}

	solver *s = new solver();
	bool success = s->read_problem(input);
	if (!success) return EXIT_FAILURE;

	if (engine == "GREEDY" || engine == "ASTAR") {
        if (heuristic == "SIMPLE")
			((informed_search_engine *)(search))->set_heuristic(
					new simple_heuristic(s->get_goal())
			);
		else if (heuristic == "MANHATTAN")
			((informed_search_engine *)(search))->set_heuristic(
					new manhattan_heuristic(s->get_goal())
			);
		else {
			cout << "Wrong Heuristic usage. Use --help to get help." << endl;
			exit(EXIT_FAILURE);
		}
	}
	//search->set_heuristic(new simple_heuristic(s->get_goal()));

	s->get_init()->print();
	s->get_goal()->print();

	s->set_engine(search);
	s->run_search();
	s->write_solution(output);

	return EXIT_SUCCESS;
}

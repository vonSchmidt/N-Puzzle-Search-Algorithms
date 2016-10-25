#N-Puzzle Problem Solver

##Available Search Algorithms
	* Breadth First Search
	* Depth First Search
	* Uniform Cost Search
	* Depth Limited Search
	* Iterative Deepening Search
	* Greedy Best First Search
	* A\* Best First Search

##Available Heuristics Estimates
In order to run informed search algorithms, we use the following estimates:
	* Simple N-Puzzle Heuristic: Estimate the distance to the goal by computing
	  the number of misplaced tiles.
	* Manhattan Distance Heuristic: Estimate the distance to the goal by
	  computing the amount of steps needed to move a tile to its correct
	  position, considering there are no obstacles in the process of doing so.

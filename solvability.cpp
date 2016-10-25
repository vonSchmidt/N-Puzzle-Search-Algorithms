#include <math.h>

using namespace std;
int getindex(small_integer *arr, int n, small_integer size_puzzle) {
	int i;
	for(i=0; i<size_puzzle+1; i++) {
		if(arr[i]==n)
			return i;
	}
	return -1;
}
bool isSolvable(small_integer *puzzle,small_integer *goal, small_integer size_puzzle) {
	int parity = 0;
	int gridWidth = (int) sqrt(size_puzzle+1);
	int row = 0; // the current row we are on
	int blankRow = 0; // the row with the blank tile

	for (int i = 0; i < size_puzzle+1; i++) {
		if (i % gridWidth == 0) { // advance to next row
			row++;
		}
		if (puzzle[i] == 0) { // the blank tile
			blankRow = row; // save the row on which encountered
			continue;
		}
		for (int j = i + 1; j < size_puzzle+1; j++) {
			if (getindex(goal,puzzle[i],size_puzzle) > getindex(goal,puzzle[j],size_puzzle) && puzzle[j] != 0) {
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


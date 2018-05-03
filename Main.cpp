#include "Board.h";
#include "HardestSudoku.cpp";
//#include "EasySudoku.cpp";
#include "BoardDrawer.cpp";
#include <iostream>;
#include <string>;
#include "Solver.h";

using std::cout;

int main() {
	HardestSudoku hs;
	//EasySudoku es;

	vector<vector<int>> hardestSudoku = hs.return_board();

	Board* sudokuBoard = new Board(hardestSudoku);
	BoardDrawer* drawer = new BoardDrawer();

	//check solver
	Solver solver = Solver(sudokuBoard);
	solver.solve();

	return 0;
};
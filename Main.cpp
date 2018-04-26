#include "Board.h";
#include "HardestSudoku.cpp";
//#include<vector>;
//using std::vector;

int main() {
	HardestSudoku* hardestSudokuCreator = new HardestSudoku();
	vector<vector<int>> hardestSudoku = hardestSudokuCreator->returnHardestSudoku();

	Board* sudokuBoard = new Board(hardestSudoku);
	sudokuBoard->drawBoard(hardestSudoku);

	sudokuBoard->playMove(0, 1, 9);
	sudokuBoard->drawBoard(sudokuBoard->board);

	return 0;
};
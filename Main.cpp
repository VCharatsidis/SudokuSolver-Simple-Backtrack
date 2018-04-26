#include "Board.h";
#include "HardestSudoku.cpp";
//#include<vector>;
//using std::vector;

int main() {
	HardestSudoku* hardestSudokuCreator = new HardestSudoku();
	vector<vector<int>> hardestSudoku = hardestSudokuCreator->returnHardestSudoku();

	Board* sudokuBoard = new Board(hardestSudoku);
	sudokuBoard->drawBoard(hardestSudoku);

	SudokuMove* move = new SudokuMove();
	move->x = 0;
	move->y = 1;
	move->value = 0;

	sudokuBoard->playMove(*move);
	sudokuBoard->drawBoard(sudokuBoard->board);

	return 0;
};
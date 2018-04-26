#include "Board.h";
#include "HardestSudoku.cpp";
#include "BoardDrawer.cpp";
//#include<vector>;
//using std::vector;

int main() {
	HardestSudoku* hardestSudokuCreator = new HardestSudoku();
	vector<vector<int>> hardestSudoku = hardestSudokuCreator->returnHardestSudoku();

	Board* sudokuBoard = new Board(hardestSudoku);
	BoardDrawer* drawer = new BoardDrawer();

	drawer->draw_board(hardestSudoku);

	SudokuMove* move = new SudokuMove();
	move->x = 0;
	move->y = 1;
	move->value = 9;

	sudokuBoard->playMove(*move);
	drawer->draw_board(sudokuBoard->board);

	/*sudokuBoard->undoMove();
	drawer->draw_board(sudokuBoard->board);*/

	return 0;
};
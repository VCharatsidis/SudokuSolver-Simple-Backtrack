#include "Board.h";
#include "HardestSudoku.cpp";
#include "BoardDrawer.cpp";
#include <tuple>;
//#include<vector>;
//using std::vector;
using std::tuple;

int main() {
	HardestSudoku* hardestSudokuCreator = new HardestSudoku();
	vector<vector<int>> hardestSudoku = hardestSudokuCreator->returnHardestSudoku();

	Board* sudokuBoard = new Board(hardestSudoku);
	BoardDrawer* drawer = new BoardDrawer();

	drawer->draw_board(hardestSudoku);

	SudokuMove* move = new SudokuMove();
	
	std::get<0>(move->coordinates) = 0 ;
	std::get<1>(move->coordinates) = 1 ;
	move->value = 7;

	sudokuBoard->play_move(*move);
	drawer->draw_board(sudokuBoard->board);

	sudokuBoard->undo_move();
	drawer->draw_board(sudokuBoard->board);

	return 0;
};
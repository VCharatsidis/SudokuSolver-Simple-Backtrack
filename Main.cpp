#include "Board.h";
#include "HardestSudoku.cpp";
#include "BoardDrawer.cpp";
#include <tuple>;
#include <iostream>;
#include <string>;

using std::tuple;
using std::cout;

int main() {
	HardestSudoku* hardestSudokuCreator = new HardestSudoku();
	vector<vector<int>> hardestSudoku = hardestSudokuCreator->returnHardestSudoku();

	Board* sudokuBoard = new Board(hardestSudoku);
	BoardDrawer* drawer = new BoardDrawer();

	//test draw_board and HardestSudoku.
	drawer->draw_board(hardestSudoku);

	SudokuMove* move = new SudokuMove();
	
	std::get<0>(move->coordinates) = 0 ;
	std::get<1>(move->coordinates) = 1 ;
	move->value = 7;

	//test play_move;
	sudokuBoard->play_move(*move);
	drawer->draw_board(sudokuBoard->board);

	//test undo_move;
	sudokuBoard->undo_move();
	drawer->draw_board(sudokuBoard->board);

	// test empty_boxes;
	stack<tuple<int, int>> eb = sudokuBoard->empty_boxes();
	int number_of_empty_boxes = eb.size();
	cout << "empty boxes number " + std::to_string(number_of_empty_boxes) << std::endl;
	
	for (int i = 0; i < number_of_empty_boxes; i++) {
		int x = std::get<0>(eb.top());
		int y = std::get<1>(eb.top());
		eb.pop();
		cout << std::to_string(x)+","+ std::to_string(y) + " | ";
	}

	return 0;
};
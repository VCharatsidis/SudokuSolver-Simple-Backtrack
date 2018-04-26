#include "Board.h";
#include <math.h>;

int empty_box = 0;
int sudoku_size = 9;
vector<vector<int>> Board::board(sudoku_size, vector<int>(sudoku_size, empty_box));
stack<SudokuMove> Board::moves_done;

Board::Board(vector<vector<int>> board) {
	for (int row = 0; row < sudoku_size; row++) {
		for (int column = 0; column < sudoku_size; column++) {
			assign_value(row, column, board[row][column]);
		}
	}
}

void Board::assign_value(int row, int column, int value) {
	Board::board[row][column] = value;
}

void Board::play_move(SudokuMove move) {
	int row = std::get<0>(move.coordinates);
	int column = std::get<1>(move.coordinates);

	int value = move.value;

	assign_value(row, column, value);
	Board::moves_done.push(move);
}

void Board::undo_move() {
	SudokuMove move_to_undo = Board::moves_done.top();
	int row = std::get<0>(move_to_undo.coordinates);
	int column = std::get<1>(move_to_undo.coordinates);

	assign_value(row, column, empty_box);
	Board::moves_done.pop();	
}

bool Board::is_empty(int row, int column) {
	return Board::board[row][column] == empty_box;
}

stack<tuple<int, int>> Board::empty_boxes() {
	stack<tuple<int, int>> emptyBoxes;

	for (int row = 0; row < sudoku_size; row++) {
		for (int column = 0; column < sudoku_size; column++) {
			if (Board::is_empty(row, column)) {
				tuple<int, int> empty_box(row, column);
				emptyBoxes.push(empty_box);
			}
		}
	}

	return emptyBoxes;
}

stack<SudokuMove> Board::legal_moves() {
	stack<tuple<int, int>> emptyBoxes = empty_boxes();

	while (!emptyBoxes.empty()) {
		tuple<int, int> box = emptyBoxes.top();
		int x = std::get<0>(emptyBoxes.top());
		int y = std::get<1>(emptyBoxes.top());

	}
}

vector<int> Board::find_container_box(int row, int column) {
	double container_box_size = sqrt(sudoku_size);

	int x = intpart(row, container_box_size);
	int y = intpart(column, container_box_size);
}

int Board::intpart(int coordinate, double container_box_size) {
	int intpart = coordinate / container_box_size;
	return intpart;
	/*modf(container_box_size, &intpart);

	return static_cast<int>(intpart);*/
}







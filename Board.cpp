#include "Board.h";
#include <math.h>;

int empty_box_value = 0;
int sudoku_size = 9;
int container_size = sqrt(sudoku_size);

vector<vector<int>> Board::board(sudoku_size, vector<int>(sudoku_size, empty_box_value));
stack<SudokuMove> Board::moves_done;

Board::Board(vector<vector<int>> board) {
	for (int row = 0; row < sudoku_size; row++) {
		for (int column = 0; column < sudoku_size; column++) {
			Box* box = new Box(row, column);
			assign_value(*box, board[row][column]);
		}
	}
}

void Board::assign_value(Box box, int value) {
	Board::board[box.row][box.column] = value;
}

void Board::play_move(SudokuMove move) {
	int value = move.value;

	assign_value(*move.box, value);
	Board::moves_done.push(move);
}

void Board::undo_move() {
	SudokuMove move_to_undo = Board::moves_done.top();

	assign_value(*move_to_undo.box, empty_box_value);
	Board::moves_done.pop();	
}

bool Board::is_empty(Box box) {
	return Board::board[box.row][box.column] == empty_box_value;
}

stack<Box> Board::empty_boxes() {
	stack<Box> emptyBoxes;

	for (int row = 0; row < sudoku_size; row++) {
		for (int column = 0; column < sudoku_size; column++) {
			Box* box = new Box(row, column);
			
			if (Board::is_empty(*box)) {
				emptyBoxes.push(*box);
			}
		}
	}

	return emptyBoxes;
}

stack<SudokuMove> Board::legal_moves() {
	stack<Box> emptyBoxes = empty_boxes();
	bool empty_box_exists = !emptyBoxes.empty();

	while (empty_box_exists) {
		Box box = emptyBoxes.top();

		int x = box.row;
		int y = box.column;

	}
}

Box Board::find_container_starting_box(Box box) {
	int container_x = box.row/container_size;
	int container_y = box.column/container_size;

	int starting_box_x = container_x * container_size;
	int starting_box_y = container_y * container_size;

	Box* starting_box = new Box(starting_box_x, starting_box_y);
	return *starting_box;
}
 







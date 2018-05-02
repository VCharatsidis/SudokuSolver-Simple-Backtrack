#include "Board.h";
#include <math.h>;
#include "Scores.h";
#include <string>;
#include <iostream>;

int empty_box_value = 0;
int container_size;

int Board::sudoku_size;
vector<vector<int>> Board::board;//(sudoku_size, vector<int>(sudoku_size, empty_box_value));
stack<SudokuMove> Board::moves_done;

Board::Board(vector<vector<int>> board) {
	sudoku_size = board.size();
	container_size = sqrt(sudoku_size);
	Board::board = board;
	/*for (int row = 0; row < sudoku_size; row++) {
		for (int column = 0; column < sudoku_size; column++) {
			Box* box = new Box(row, column);
			int value = board[row][column];

			assign_value(*box, value);
		}
	}*/
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
			Box box = Box(row, column);
			
			if (Board::is_empty(box)) {
				emptyBoxes.push(box);
			}
		}
	}
	return emptyBoxes;
}

vector<SudokuMove> Board::legal_moves() {
	vector<SudokuMove> legal_moves;
	stack<Box> empty_boxes = Board::empty_boxes();
	std::cout << " empty_boxes size " +std::to_string(empty_boxes.size()) << std::endl;
	bool empty_box_exists = !empty_boxes.empty();

	while (empty_box_exists) {
		Box* box = &empty_boxes.top();
		
		for (int value = 1; value < sudoku_size+1; value++) {
			SudokuMove move ;
	
			move.box = box;
			move.value = value;

			if (is_move_valid(move)) {
				legal_moves.push_back(move);
			}
		}

		empty_boxes.pop();
		empty_box_exists = !empty_boxes.empty();
	}
	return legal_moves;
}

bool Board::is_move_valid(SudokuMove move) {
	int row = move.box->row;
	int column = move.box->column;
	int value = move.value;

	bool valid_row = is_value_valid(board[row], value);

	if (valid_row) {
		
		vector<int> column_boxes = gather_column_boxes(column);
		bool valid_column = is_value_valid(column_boxes, value);

		if (valid_column) {
			
			Box box = find_container_starting_box(*move.box);
			vector<int> container_boxes = gather_container_boxes(box);
			bool valid_container = is_value_valid(container_boxes, value);

			if (valid_container) {
				return true;
			}
		}
	}
	return false;
}

vector<int> Board::gather_column_boxes(int given_column) {
	vector<int> column_boxes;

	for(int row = 0; row < sudoku_size; row++) {
		column_boxes.push_back(Board::board[row][given_column]);
	}

	return column_boxes;
}

vector<int> Board::gather_container_boxes(Box starting_box) {
	vector<int> container_boxes;

	int start_row = starting_box.row;
	int end_row = start_row + container_size;
	int start_column = starting_box.column;
	int end_column = start_column + container_size;

	//std::cout << " start_row " + std::to_string(start_row) + " start_column " + std::to_string(start_column) << std::endl;
	for (int x = start_row; x < end_row; x++) {
		for (int y = start_column; y < end_column; y++) {
			container_boxes.push_back(Board::board[x][y]);
		}
	}

	return container_boxes;
}

bool Board::is_value_valid(vector<int> box_structure, int value) {
	int box_structure_size = box_structure.size();

	for (int box = 0; box < box_structure_size; box++) {
		
		int box_value = box_structure[box];
		
		bool is_not_valid = (box_value == value);

		if (is_not_valid) {
			return false;
		}	
	}

	return true;
}

Box Board::find_container_starting_box(Box box) {
	
	int container_x = box.row/container_size;
	int container_y = box.column/container_size;

	int starting_box_x = container_x * container_size;
	int starting_box_y = container_y * container_size;

	Box* starting_box = new Box(starting_box_x, starting_box_y);
	return *starting_box;
}

bool Board::game_over() {
	stack<Box> empties = empty_boxes();
	bool game_over = (empties.size() == 0);

	if (game_over) {
		return true;
	}
	else {
		return false;
	}
}
 







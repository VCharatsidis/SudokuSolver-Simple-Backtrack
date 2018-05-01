#include "Board.h";
#include <math.h>;
#include "Scores.h";
#include <string>;
#include <iostream>;

int empty_box_value = 0;
int sudoku_size = 9;
int container_size = sqrt(sudoku_size);

vector<vector<int>> Board::board(sudoku_size, vector<int>(sudoku_size, empty_box_value));
stack<SudokuMove> Board::moves_done;

Board::Board(vector<vector<int>> board) {
	for (int row = 0; row < sudoku_size; row++) {
		for (int column = 0; column < sudoku_size; column++) {
			Box* box = new Box(row, column);
			int value = board[row][column];

			assign_value(*box, value);
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
	stack<SudokuMove> legal_moves;

	stack<Box> empty_boxes = Board::empty_boxes();
	bool empty_box_exists = !empty_boxes.empty();

	while (empty_box_exists) {
		Box box = empty_boxes.top();

		for (int value = 1; value < sudoku_size+1; value++) {
			SudokuMove* move = new SudokuMove();
	
			move->box = &box;
			move->value = value;

			if (is_move_valid(*move)) {
				legal_moves.push(*move);
			}
		}

		empty_boxes.pop();
	}
	return legal_moves;
}

bool Board::is_move_valid(SudokuMove move) {
	int row = move.box->row;
	int column = move.box->column;
	int value = move.value;

	bool valid_row = validity_check(board[row], value);

	if (valid_row) {
		vector<int> column_boxes = gather_column_boxes(column);
		bool valid_column = validity_check(column_boxes, value);

		if (valid_column) {
			vector<int> container_boxes = gather_container_boxes(*move.box);
			bool valid_container = validity_check(container_boxes, value);

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

	for (int x = start_row; x < end_row; x++) {
		for (int y = start_column; y < end_column; y++) {
			container_boxes.push_back(Board::board[x][y]);
		}
	}

	return container_boxes;
}

bool Board::validity_check(vector<int> box_structure, int value) {
	int box_structure_size = box_structure.size();
	double structure_score = 0;
	bool is_valid = false;

	Scores* score_board = Scores::instance();
	double value_score = score_board->scores[value]; 

	for (int box = 0; box < box_structure_size; box++) {
		int box_value = box_structure[box];
		double current_score = score_board->scores[box_value];

		structure_score += current_score;
	}
	std::cout << "structure_score " + std::to_string(structure_score)+ " value_score " + std::to_string(value_score) << std::endl;
	
	if (structure_score == value_score) {
		is_valid = false;
		return is_valid;
	}
	else if ((structure_score*2) < value_score) {
		is_valid = true;
		return is_valid;
	}
	else {
		int score_over_value = structure_score / value_score;
		std::cout << "score_over_value " + std::to_string(score_over_value) << std::endl;

		bool value_not_exists_in_structure = (score_over_value % 2 == 0);
		
		if (value_not_exists_in_structure) {
			is_valid = true;
			return is_valid;
		}
		else {
			is_valid = false;
			return is_valid;
		}
	}

	return is_valid;	
}


Box Board::find_container_starting_box(Box box) {
	int container_x = box.row/container_size;
	int container_y = box.column/container_size;

	int starting_box_x = container_x * container_size;
	int starting_box_y = container_y * container_size;

	Box* starting_box = new Box(starting_box_x, starting_box_y);
	return *starting_box;
}
 







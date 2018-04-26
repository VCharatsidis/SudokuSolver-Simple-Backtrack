#include "Board.h";

int empty_box = 0;
int sudoku_size = 9;
vector<vector<int>> Board::board(sudoku_size, vector<int>(sudoku_size, empty_box));
stack<SudokuMove> Board::moves_done;

Board::Board(vector<vector<int>> board) {
	for (int i = 0; i < sudoku_size; i++) {
		for (int j = 0; j < sudoku_size; j++) {
			assign_value(i, j, board[i][j]);
		}
	}
}

void Board::assign_value(int x, int y, int value) {
	Board::board[x][y] = value;
}

void Board::play_move(SudokuMove move) {
	int x = std::get<0>(move.coordinates);
	int y = std::get<1>(move.coordinates);

	int value = move.value;

	assign_value(x, y, value);
	Board::moves_done.push(move);
}

void Board::undo_move() {
	SudokuMove move_to_undo = Board::moves_done.top();
	int x = std::get<0>(move_to_undo.coordinates);
	int y = std::get<1>(move_to_undo.coordinates);

	assign_value(x, y, empty_box);
	Board::moves_done.pop();	
}

bool Board::is_empty(int x, int y) {
	return Board::board[x][y] == empty_box;
}

stack<SudokuMove> Board::legal_moves() {

}







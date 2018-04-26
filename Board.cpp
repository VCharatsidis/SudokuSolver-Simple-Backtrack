#include "Board.h";

int empty_box = 0;
int sudoku_size = 9;
vector<vector<int>> Board::board(sudoku_size, vector<int>(sudoku_size, empty_box));
stack<SudokuMove> Board::moves_done;

Board::Board(vector<vector<int>> board) {

	for (int i = 0; i < sudoku_size; i++) {
		for (int j = 0; j < sudoku_size; j++) {
			Board::board[i][j] = board[i][j];
		}
	}
}

void Board::playMove(SudokuMove move) {
	Board::board[move.x][move.y] = move.value;
	Board::moves_done.push(move);
}

void Board::undoMove() {
	SudokuMove move_to_undo = Board::moves_done.top();

	Board::board[move_to_undo.x][move_to_undo.y] = empty_box;
	Board::moves_done.pop();	
}





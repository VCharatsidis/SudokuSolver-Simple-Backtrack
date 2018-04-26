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

void Board::drawBoard(vector<vector<int>> board) {
	const string file_path = "C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt";
	const string horizontal_line_serparator = "----------------------";
	const string vertical_line_separator = "| ";

	const int horizontalLines = 2;
	int boardSize = board.size();

	int drawHeight = boardSize + horizontalLines;
	int drawWidth = boardSize;

	std::ofstream myfile;
	myfile.open(file_path);

	int horizontalLineCounter = 0;

	for (int row = 0; row < drawHeight; row++) {
		bool drawHorizontalLine = ((row + 1) % 4 == 0);

		if (drawHorizontalLine) {
			myfile << horizontal_line_serparator;
			horizontalLineCounter++;
		}
		else {
			for (int column = 0; column < drawWidth; column++) {
				bool drawVerticalLine = (column % 3 == 0 && column > 0);

				if (drawVerticalLine) {
					myfile << vertical_line_separator;
				}
				
				int value = board[row - horizontalLineCounter][column];
				string valueToString = std::to_string(value);

				if (value == 0) {
					valueToString = "_";
				}
				
				myfile << valueToString  + " ";
			}
		}
		myfile << "\n";
	}
	myfile.close();
}



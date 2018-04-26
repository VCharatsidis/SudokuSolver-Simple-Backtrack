#include "Board.h";

vector<vector<int>> Board::board(9, vector<int>(9, 0));

Board::Board(vector<vector<int>> board) {

	int boardSize = board.size();

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			Board::board[i][j] = board[i][j];
		}
	}
}

void Board::playMove(SudokuMove move) {
	Board:board[move.x][move.y] = move.value;
}

void Board::undoMove() {
	
}

void Board::drawBoard(vector<vector<int>> board) {
	const string filePath = "C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt";
	const string horizontal_line_serparator = "----------------------";
	const string vertical_line_separator = "| ";

	const int horizontalLines = 2;
	int boardSize = board.size();

	int drawHeight = boardSize + horizontalLines;
	int drawWidth = boardSize;

	std::ofstream myfile;
	myfile.open(filePath);

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



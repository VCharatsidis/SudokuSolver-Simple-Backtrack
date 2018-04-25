#include "Board.h";

string Board::filePath = "C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt";
string Board::horizontal_line_serparator = "----------------------";
string Board::vertical_line_separator = "| ";
vector<vector<int>> Board::board(9, vector<int>(9, 0));

Board::Board(vector<vector<int>> board) {

	int boardSize = board.size();

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			Board::board[i][j] = board[i][j];
		}
	}
}

void Board::drawBoard() {
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
				myfile << std::to_string(value) + " ";
			}
		}
		myfile << "\n";
	}
	myfile.close();
}



#include<array>;
#include<vector>;
#include<iostream>;
#include<string>;
#include<fstream>;
#include<string>;

using std::vector;
using std::cout;

class Board {

public:
	
	static vector<vector<int>> board;
	static int size;
	std::string const filePath = "C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt";
	std::string const horizontal_line_serparator = "----------------------";
	std::string const vertical_line_separator = "| ";

	Board(vector<vector<int>> board) {
		size = board.size();

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Board::board[i][j] = board[i][j];
			}
		}
	}

	void print(vector<vector<int>> board) {
		const int horizontalLines = 2;
		int boardHeight = board.size() + horizontalLines;
		int boardWidth = board.size();
		std::ofstream myfile;
		myfile.open(filePath);
		int horizontalLineCounter = 0;

		for (int row = 0; row < boardHeight; row++) {
			bool drawHorizontalLine = ((row + 1) % 4 == 0);

			if (drawHorizontalLine) {
				myfile << horizontal_line_serparator;
				horizontalLineCounter++;
			}
			else {
				for (int column = 0; column < boardWidth; column++) {
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

};
#include <array>;
#include <vector>;
#include <iostream>;
#include <string>;
#include <fstream>;

using std::vector;
using std::string;

class BoardDrawer {
public:
	const string file_path = "C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt";
	const string horizontal_line_serparator = "----------------------";
	const string vertical_line_separator = "| ";
	const string empty_box = "_";
	const int horizontalLines = 2;

	void draw_board(vector<vector<int>> board) {
		int boardSize = board.size();
	
		int drawHeight = boardSize + horizontalLines;
		int drawWidth = boardSize;

		std::ofstream myfile;
		myfile.open(file_path);

		int horizontal_line_counter = 0;

		for (int row = 0; row < drawHeight; row++) {
			bool drawHorizontalLine = ((row + 1) % 4 == 0);

			if (drawHorizontalLine) {
				myfile << horizontal_line_serparator;
				horizontal_line_counter++;
			}
			else {
				for (int column = 0; column < drawWidth; column++) {
					bool drawVerticalLine = (column % 3 == 0 && column > 0);

					if (drawVerticalLine) {
						myfile << vertical_line_separator;
					}

					int value = board[row - horizontal_line_counter][column];
					string valueToString = std::to_string(value);

					if (value == 0) {
						valueToString = empty_box;
					}

					myfile << valueToString + " ";
				}
			}
			myfile << "\n";
		}
		myfile.close();
	}

	string place(int place) {
		string space = "";

		for (int i = 0; i < place; i++) {
			space = space + " ";
		}

		return space;
	}
};
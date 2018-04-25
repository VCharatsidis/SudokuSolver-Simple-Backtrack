#include<array>;
#include<vector>;
#include<iostream>;
#include<string>;
#include<fstream>;

using std::vector;
using std::cout;

void print(vector<vector<int>> board) {
	const int horizontalLines = 2;
	int boardHeight = board.size() + horizontalLines;
	int boardWidth = board.size();
	std::ofstream myfile;
	myfile.open("C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt");
	int horizontalLineCounter = 0 ;

	for (int row = 0; row < boardHeight; row++) {
		bool drawHorizontalLine = ((row + 1) % 4 == 0);

		if (drawHorizontalLine) {
			myfile << "----------------------";
			horizontalLineCounter++;
		}
		else {
			for (int column = 0; column < boardWidth; column++) {
				bool drawVerticalLine = (column % 3 == 0 && column > 0);

				if (drawVerticalLine) {
					myfile << "| " + std::to_string(board[row - horizontalLineCounter][column]) + " ";
				}
				else {
					myfile << std::to_string(board[row - horizontalLineCounter][column]) + " ";
				}
			}
		}
		
		myfile << "\n";
	}
	myfile.close();
}

int main() {
	vector<vector<int>> hardestSudoku(9, vector<int>(9,0));
	print(hardestSudoku);

};
#include<array>;
#include<vector>;
#include<iostream>;
#include<string>;
#include<fstream>;

using std::vector;
using std::cout;

void print(vector<vector<int>> board) {
	int size = board.size();
	std::ofstream myfile;
	myfile.open("C:\\Users\\vcharatsidis\\Desktop\\sudoku.txt");

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j % 3 == 0 && j>0 ) {
				myfile << "| "+std::to_string(board[i][j]) + " ";
			}
			else {
				myfile << std::to_string(board[i][j]) + " ";
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
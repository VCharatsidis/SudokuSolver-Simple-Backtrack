#include "Board.h";
//#include<vector>;
//using std::vector;

int main() {
	vector<vector<int>> hardestSudoku(9, vector<int>(9,0));
	Board* sudokuBoard = new Board(hardestSudoku);
	sudokuBoard->drawBoard;

};
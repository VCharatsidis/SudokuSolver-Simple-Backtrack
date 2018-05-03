#include "SudokuLibrary.cpp";

class EasySudoku : public ISudokuLibrary {
public:
	vector<vector<int>> return_board() {
		vector<vector<int>> easySudoku(9, vector<int>(9, 0));

		easySudoku[0][0] = 4;
		easySudoku[0][2] = 1;
		easySudoku[0][3] = 2;
		easySudoku[0][4] = 9;
		easySudoku[0][7] = 7;
		easySudoku[0][8] = 5;

		easySudoku[1][0] = 2;
		easySudoku[1][3] = 3;
		easySudoku[1][6] = 8;

		easySudoku[2][1] = 7;
		easySudoku[2][4] = 8;
		easySudoku[2][8] = 6;

		easySudoku[3][3] = 1;
		easySudoku[3][5] = 3;
		easySudoku[3][7] = 6;
		easySudoku[3][8] = 2;

		easySudoku[4][0] = 1;
		easySudoku[4][2] = 5;
		easySudoku[4][6] = 4;
		easySudoku[4][8] = 3;

		easySudoku[5][0] = 7;
		easySudoku[5][1] = 3;
		easySudoku[5][3] = 6;
		easySudoku[5][5] = 8;

		easySudoku[6][0] = 6;
		easySudoku[6][4] = 2;
		easySudoku[6][7] = 3;

		easySudoku[7][2] = 7;
		easySudoku[7][5] = 1;
		easySudoku[7][8] = 4;

		easySudoku[8][0] = 8;
		easySudoku[8][1] = 9;
		easySudoku[8][4] = 6;
		easySudoku[8][5] = 5;
		easySudoku[8][6] = 1;
		easySudoku[8][8] = 7;

		return easySudoku;
	}
};
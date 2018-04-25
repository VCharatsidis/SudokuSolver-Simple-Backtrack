#include<vector>;
using std::vector;

class HardestSudoku{
public:
	vector<vector<int>> returnHardestSudoku() {
		vector<vector<int>> hardestSudoku(9, vector<int>(9, 0));

		hardestSudoku[0][0] = 8;

		hardestSudoku[1][2] = 3;
		hardestSudoku[1][3] = 6;

		hardestSudoku[2][1] = 7;
		hardestSudoku[2][4] = 9;
		hardestSudoku[2][6] = 2;

		hardestSudoku[3][1] = 5;
		hardestSudoku[3][5] = 7;

		hardestSudoku[4][4] = 4;
		hardestSudoku[4][5] = 5;
		hardestSudoku[4][6] = 7;

		hardestSudoku[5][3] = 1;
		hardestSudoku[5][7] = 3;

		hardestSudoku[6][2] = 1;
		hardestSudoku[6][7] = 6;
		hardestSudoku[6][8] = 8;

		hardestSudoku[7][2] = 8;
		hardestSudoku[7][3] = 5;
		hardestSudoku[7][7] = 8;

		hardestSudoku[8][1] = 9;
		hardestSudoku[8][6] = 4;

		return hardestSudoku;
	}
};
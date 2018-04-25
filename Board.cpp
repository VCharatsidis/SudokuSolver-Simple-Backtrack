#include<array>;
#include<vector>;
#include<iostream>;
#include<string>;

using std::vector;
using std::cout;

class Board {

public:
	
	static vector<vector<int>> board;
	static int size;

	Board(vector<vector<int>> board) {
		size = board.size();

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Board::board[i][j] = board[i][j];
			}
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << std::to_string(board[i][j])+" ";
			}
			cout <<std::endl;
		}
	}
};
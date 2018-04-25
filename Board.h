#pragma once
#include <array>;
#include <vector>;
#include <iostream>;
#include <string>;
#include <fstream>;

using std::vector;
using std::string;

class Board {
public:

	static vector<vector<int>> board;

	Board(vector<vector<int>> board);
	static void drawBoard(vector<vector<int>> board);
};




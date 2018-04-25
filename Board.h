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
	static string filePath;
	static string horizontal_line_serparator;
	static string vertical_line_separator;

	Board(vector<vector<int>> board);
	static void drawBoard();
};




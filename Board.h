#pragma once
#include <vector>;
#include <string>;
#include <stack>;
#include "SudokuMove.cpp";

using std::vector;
using std::string;
using std::stack;

class Board {
public:

	static vector<vector<int>> board;
	static stack<SudokuMove> moves_done;

	Board(vector<vector<int>> board);
	static void playMove(SudokuMove move);
	static void undoMove();
	static void assign_value(int x, int y, int value);
};




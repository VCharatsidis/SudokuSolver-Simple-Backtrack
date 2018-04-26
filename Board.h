#pragma once
#include <array>;
#include <vector>;
#include <iostream>;
#include <string>;
#include <fstream>;
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
};




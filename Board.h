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
	static void play_move(SudokuMove move);
	static void undo_move();
	static void assign_value(int x, int y, int value);
	static stack<SudokuMove> legal_moves();
	static bool is_empty(int x, int y);
};




#pragma once
#include <vector>;
#include <string>;
#include <stack>;
#include "SudokuMove.cpp";

using std::vector;
using std::string;
using std::stack;
using std::tuple;

class Board {
public:

	static vector<vector<int>> board;
	static stack<SudokuMove> moves_done;
	//static Scores*

	Board(vector<vector<int>> board);
	static void play_move(SudokuMove move);
	static void undo_move();
	static void assign_value(Box box, int value);
	static stack<SudokuMove> legal_moves();
	static bool is_empty(Box box);
	static stack<Box> empty_boxes();
	static Box find_container_starting_box(Box b);
};




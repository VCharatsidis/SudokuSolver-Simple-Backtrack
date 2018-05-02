#include "Solver.h";
#include "BoardDrawer.cpp";

//Board* Solver::board;
int trials = 0;
int size ;
Board* to_solve;

Solver::Solver(Board* board) {
	to_solve = board;
	size = board->sudoku_size;
};

void Solver::solve() {

	if (to_solve->game_over()) {
		BoardDrawer* drawer = new BoardDrawer();
		drawer->draw_board(to_solve->board);
		return;
	}
	
	vector<SudokuMove> moves = to_solve->legal_moves();
	bool move_exist = (moves.size() > 0);

	if (!move_exist) {
		return;
	}

	for (int i = 0; i < moves.size(); i++) {
		SudokuMove* m = new SudokuMove();
		m =	&moves[i];
		Box b = *m->box;
		int x = b.row;
		int y = b.column;
		std::cout << std::to_string(x) +", "+ std::to_string(y) << std::endl;
		to_solve->play_move(*m);
		BoardDrawer* drawer = new BoardDrawer();
		drawer->draw_board(to_solve->board);
		solve();

		if (to_solve->game_over()) {
			return;
		}
		else {
			to_solve->undo_move();
		}
	}
	
}
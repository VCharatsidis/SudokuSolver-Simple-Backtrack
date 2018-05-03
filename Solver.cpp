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
	bool game_over = to_solve->game_over();

	if (game_over) {
		BoardDrawer* drawer = new BoardDrawer();
		drawer->draw_board(to_solve->board);
		return;
	}

	for (int row = 0; row < size; row++) {
		for (int column = 0; column < size; column++) {
			Box box = Box(row, column);
			bool is_empty = to_solve->is_empty(box);

			if (is_empty) {
				for (int value = 1; value < size + 1; value++) {
					SudokuMove* move = new SudokuMove;
					Box* box = new Box(row, column);
					move->value = value;
					move->box = box;
					bool is_valid = to_solve->is_move_valid(*move);

					if (is_valid) {
						to_solve->play_move(move);
						/*BoardDrawer* drawer = new BoardDrawer();
						drawer->draw_board(to_solve->board);*/

						solve();

						if (to_solve->game_over()) {
							return;
						}
						else {
							to_solve->undo_move();
							delete box;
							delete move;
						}
					}
				}
				return;
			}
		}	
	}
	
}
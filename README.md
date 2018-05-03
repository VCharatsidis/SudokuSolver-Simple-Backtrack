# SudokuSolverCpp
Sudoku solver in cpp

This solver tries recursively to fill the empty boxes according to Sudoku laws.
Lazily tries to fill the first empty box that it finds.
If there is not a valid value to fit into the empty box the recurssion stops.
The last move is undone and the recursion continues until all the boxes are filled.

There is an interface as virtual class (ISudokuLibrary).
This interface is implemented by HardestSudoku and EasySudoku which provides the hardest sudoku ever made by a Finish mathematician
and a common easy sudoku respectively.


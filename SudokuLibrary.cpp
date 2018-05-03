#include <vector>
using std::vector;

class ISudokuLibrary {
public:
	virtual vector<vector<int>> return_board() = 0;
};
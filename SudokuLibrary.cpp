#include <vector>
using std::vector;

class ISudokuLibrary {
public:

	//virtual ~ISudokuLibrary() = 0;
	virtual vector<vector<int>> return_board() = 0;
};
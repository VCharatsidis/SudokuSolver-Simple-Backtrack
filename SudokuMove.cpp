#include <tuple>
using std::tuple;

struct SudokuMove{
	tuple<int, int> coordinates;
	int value;
};
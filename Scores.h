#include <unordered_map>;
using std::unordered_map;

/* Singleton class */

class Scores {
public:
	static Scores* instance();
	static unordered_map<int, double> scores;
	
private:
	Scores() {};
	Scores(Scores const&) {};
	static Scores* m_pInstance;

};
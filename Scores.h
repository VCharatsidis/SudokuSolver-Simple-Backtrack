#include <hash_map>;
using std::hash_map;

/* Singleton class */

class Scores {
public:
	static Scores* instance();
	static hash_map<int, double> scores;
	

private:
	Scores() {};
	Scores(Scores const&) {};
	static Scores* m_pInstance;

};
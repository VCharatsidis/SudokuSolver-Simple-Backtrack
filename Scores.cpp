#include <stddef.h>
#include "Scores.h"

using std::pair;

Scores* Scores::m_pInstance = NULL;
unordered_map<int, double> Scores::scores;

Scores* Scores::instance() {
	
	if (!m_pInstance) {
		m_pInstance = new Scores;

		Scores::scores.insert(pair<int, double>(0, 0.0));
		Scores::scores.insert(pair<int, double>(1, 0.001));
		Scores::scores.insert(pair<int, double>(2, 0.01));
		Scores::scores.insert(pair<int, double>(3, 0.1));
		Scores::scores.insert(pair<int, double>(4, 1.0));
		Scores::scores.insert(pair<int, double>(5, 10.0));
		Scores::scores.insert(pair<int, double>(6, 100.0));
		Scores::scores.insert(pair<int, double>(7, 1000.0));
		Scores::scores.insert(pair<int, double>(8, 10000.0));
		Scores::scores.insert(pair<int, double>(9, 100000.0));	
	}

	return m_pInstance;
}



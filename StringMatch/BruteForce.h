#include "StringMatch.h"

class BruteForce : StringMatch
{
public:
	BruteForce();
	~BruteForce();

	std::vector<int> match(std::string& p, std::string& t);
};
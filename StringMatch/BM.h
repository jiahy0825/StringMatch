#include "StringMatch.h"

class BM : StringMatch
{
public:
	BM();
	~BM();

	std::vector<int> match(std::string& p, std::string& t);
};
#include "StringMatch.h"

class KMP : StringMatch
{
public:
	KMP();
	~KMP();

	std::vector<int> match(std::string& p, std::string& t);
};
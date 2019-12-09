#include "StringMatch.h"

class KMP
{
public:
	KMP();
	~KMP();

	std::vector<int> match(std::string& p, std::string& t);
};
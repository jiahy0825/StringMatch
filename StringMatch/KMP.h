#include "stdafx.h"
#include "StringMatchAlgorithm.h"

class KMP : StringMatchAlgorithm
{
public:
	KMP();
	~KMP();

	std::vector<int> match(std::string& p, std::string& t);
};
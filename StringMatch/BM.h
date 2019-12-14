#include "stdafx.h"
#include "StringMatchAlgorithm.h"

class BM : StringMatchAlgorithm
{
public:
	BM();
	~BM();

	std::vector<int> match(std::string& p, std::string& t);
};
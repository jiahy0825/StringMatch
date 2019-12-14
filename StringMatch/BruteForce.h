#include "stdafx.h"
#include "StringMatchAlgorithm.h"

class BruteForce : StringMatchAlgorithm
{
public:
	BruteForce();
	~BruteForce();

	std::vector<int> match(std::string& p, std::string& t);
};
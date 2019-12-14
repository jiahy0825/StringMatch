#ifndef STRING_MATCH_ALGORITHM_H
#define STRING_MATCH_ALGORITHM_H

#include "stdafx.h"

#include <string>
#include <vector>

class StringMatchAlgorithm
{
public:
	StringMatchAlgorithm();
	~StringMatchAlgorithm();

	virtual std::vector<int> match(std::string& p, std::string& t) = 0;
};

#endif
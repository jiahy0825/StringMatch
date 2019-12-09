#include <string>
#include <vector>

class StringMatch
{
public:
	StringMatch();
	~StringMatch();

	virtual std::vector<int> match(std::string& p, std::string& t);
};
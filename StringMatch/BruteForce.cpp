#include "BruteForce.h"

#include <vector>

using namespace std;

BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}

vector<int> BruteForce::match(string& p, string& t){
	int m = p.length();
	int n = t.length();
	int tmp = 0;
	int i, j;
	vector<int> res;
	for(i = 0;i <= n - m;i++){
		for(j = 0;j < m;j++){
			if(p[j] != t[i + j])
				break;
		}
		if (j == m){
			res.push_back(i);
		}
	}
	return res;
}
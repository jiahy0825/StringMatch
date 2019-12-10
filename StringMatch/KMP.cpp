#include "KMP.h"

#include <vector>

using namespace std;

KMP::KMP()
{
}

KMP::~KMP()
{
}

void getNext(string& p, vector<int>& next){
	int m = p.length();
	next = vector<int>(m, -1);
	int k = -1;
	for(int i = 1;i < m;i++){
		while (k > -1 && p[k + 1] != p[i]){
			k = next[k];
		}
		if (p[k + 1] == p[i]){
			k++;
		}
		next[i] = k;
	}
}

vector<int> KMP::match(string& p, string& t){
	vector<int> res;
	int m = p.length();
	int n = t.length();
	int k = -1;
	vector<int> next;
	getNext(p, next);
	for(int i = 0;i < n;i++){
		while(k > -1 && p[k + 1] != t[i]){
			k = next[k];
		}
		if(p[k + 1] == t[i]){
			k++;
		}
		if(k == m - 1){
			res.push_back(i - k);
			k = next[k];
		}
	}
	return res;
}
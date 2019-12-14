#include "stdafx.h"
#include "BM.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

BM::BM()
{
}

BM::~BM()
{
}

vector<char> sigma;
map<char, int> bmBc;
vector<int> Osuff;
vector<int> bmGs;

void computeBMBC(string& p){
	bmBc.clear();
	int m = p.length();
	for (char c : sigma){
		bmBc[c] = m;
	}
	for (int i = 0;i < m - 1;i++){
		bmBc[p[i]] = m - i - 1;
	}
}

void computeOSUFF(string& p){
	int m = p.length();
	Osuff = vector<int>(m, 0);
	int start, end;
	Osuff[m - 1] = m;
	start = m - 1;
	for(int i = m - 2;i >= 0;i--){
		if (i > start && Osuff[m - 1 - (end - i)] < i - start){
			Osuff[i] = Osuff[m - 1 - (end - i)];
		}else{
			if (i < start){
				start = i;
			}
			end = i;
			while (start >= 0 && p[start] == p[m - 1 - (end - start)]){
				start--;
			}
			Osuff[i] = end - start;
		}
	}
}

void computeBMGS(string& p){
	int m = p.length();
	computeOSUFF(p);
	bmGs.clear();
	bmGs = vector<int>(m, m);
	for (int i = 0;i < m;i++){
		bmGs[i] = m;
	}
	int j = 0;
	for (int i = m - 1;i >= 0;i--){
		if (Osuff[i] == i + 1){
			while (j < m - i - 1){
				if (bmGs[j] == m){
					bmGs[j] = m - i - 1;
				}
				j++;
			}
		}
	}
	for (int i = 0;i <= m - 2;i++){
		bmGs[m - 1 - Osuff[i]] = m - 1 - i;
	}
}

void init_sigma(){
	char ch[28] = {',', '.', '<', '>', '?', ';', ':', '[', ']', '{', '}', 
		'-', '+', '_', '=', '|', '(', ')', '*', '&', '^', '%', '$', '#', '@', '!', '~', '`'};
	sigma = vector<char>(ch, ch + 28);
	for (char c = 'a'; c <= 'z'; c++){
		sigma.push_back(c);
	}
	for (char c = 'A'; c <= 'Z'; c++){
		sigma.push_back(c);
	}
	for (char c = '0'; c <= '9'; c++){
		sigma.push_back(c);
	}
}

vector<int> BM::match(string& p, string& t){
	vector<int> res;
	int n = t.length();
	int m = p.length();
	init_sigma();
	computeBMBC(p);
	computeBMGS(p);

	int i = m - 1;
	int s = 0;
	while (s <= n - m){
		i = m - 1;
		while (p[i] == t[s + i]){
			if (i == 0){
				res.push_back(s);
				break;
			}else{
				i--;
			}
		}
		s += max(bmGs[i], bmBc[t[s + i]] - m + i + 1);
	}
	return res;
}
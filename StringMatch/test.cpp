#include "BruteForce.h"
#include "KMP.h"
#include "BM.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> get_sigma(){
	char ch[28] = {',', '.', '<', '>', '?', ';', ':', '[', ']', '{', '}', 
		'-', '+', '_', '=', '|', '(', ')', '*', '&', '^', '%', '$', '#', '@', '!', '~', '`'};
	vector<char> sigma = vector<char>(ch, ch + 28);
	for (char c = 'a'; c <= 'z'; c++){
		sigma.push_back(c);
	}
	for (char c = 'A'; c <= 'Z'; c++){
		sigma.push_back(c);
	}
	for (char c = '0'; c <= '9'; c++){
		sigma.push_back(c);
	}
	return sigma;
}

string generatr(int len){
	vector<char> getSigma = get_sigma();
	int n = getSigma.size();
	string res = "";
	while (len-- > 0){
		res += getSigma[rand() % n];
	}
	return res;
}

int main(){
	BruteForce brute;
	KMP kmp;
	BM bm;

	string p = generatr(2);
	string t = generatr(1000000);
	cout << "p length " << p.length() <<  " t length " << t.length() << endl;

	vector<int> res1 = brute.match(p, t);
	vector<int> res2 = kmp.match(p, t);
	vector<int> res3 = bm.match(p, t);

	cout<<"res1 size : " << res1.size() << " res2 size : " << res2.size() << " res3 size : " << res3.size() << endl;

	for(int i = 0;i < res1.size();i++){
		cout<< i << " res1 : " << res1[i] << " res2 " << res2[i] << " res3 " << res3[i] << endl;
	}

	system("Pause");
}
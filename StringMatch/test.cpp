#include "BruteForce.h"
#include "KMP.h"
#include "BM.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	BruteForce brute;
	KMP kmp;
	BM bm;
	string p = "abbc";
	string t = "abbcaaabbcccsffabbcasd";
	vector<int> res1 = brute.match(p, t);
	vector<int> res2 = kmp.match(p, t);
	vector<int> res3 = bm.match(p, t);

	cout<<"res1 size : " << res1.size() << " res2 size : " << res2.size() << endl;

	for(int i = 0;i < res1.size();i++){
		cout<< i << " res1 : " << res1[i] << " res2 " << res2[i] << endl;
	}

	system("Pause");
}
/*
ID: thirtis1
PROG: barn1
LANG: C++11 
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	ofstream fout ("barn1.out"); 
	ifstream fin ("barn1.in");
	int M,S,C;
	fin >> M >> S >> C;
	if(M >= C){
		fout << C << endl;
		return 0;
	}
	int cow[C*2],dis[C*2];
	for(int i = 0;i < C;i++){
		fin >> cow[i];
	}
//	cout << wood <<endl;
	sort(cow,cow + C);
	int wood = cow[C-1] - cow[0] + 1;
	for(int i = 0;i < C-1;i++){
		dis[i] = cow[i+1] - cow[i] - 1;
	}
	sort(dis,dis + C);
	for(int i = 0;i < C-1;i++){
//		cout << dis[i] << endl;
	}
	if(M != 1){
		for(int i = 0;i < M-1;i++){
			wood -= dis[C-1-i];
//			cout << wood <<endl;
		}	
	}
	fout << wood <<endl;
	return 0;
}
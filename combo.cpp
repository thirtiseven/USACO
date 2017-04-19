/*
ID: thirtis1
PROG: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <set>

#define ture true

using namespace std;

struct password{
	int f;
	int s;
	int t;
	bool operator < (const password& b) const{
		 if(f < b.f){
		 	return true;
		}else if(f > b.f){
		 	return false;
		}else if(f == b.f){
		 	if(s < b.s){
		 		return true;
		 	}else if(s > b.s){
		 		return false;
			}else if(s == b.s){
		 		if(t < b.t){
		 			return true;
				}else{
		 			return false;
				}
			}
		}
	}
	bool operator == (const password& b) const{
		if(f == b.f && s == b.s && t == b.t){
			return true;
		}else{
			return false;
		}
	}
};

set<password> possible;

int main(int argc, char *argv[]) {
	ofstream fout ("combo.out"); 
	ifstream fin ("combo.in");
	int N;
	fin >> N;
	password farmer, master;
	fin >> farmer.f >> farmer.s >> farmer.t;
	fin >> master.f >> master.s >> master.t;
	password tempf,tempm;
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 5;j++){
			for(int h = 0;h < 5;h++){
				tempf.f = (farmer.f - 2 + i + N)%N;
				tempf.s = (farmer.s - 2 + j + N)%N;
				tempf.t = (farmer.t - 2 + h + N)%N;
				tempm.f = (master.f - 2 + i + N)%N;
				tempm.s = (master.s - 2 + j + N)%N;
				tempm.t = (master.t - 2 + h + N)%N;
				possible.insert(tempm);
				possible.insert(tempf);
			}
		}
	}
	fout << possible.size() << endl;
	return 0;
}
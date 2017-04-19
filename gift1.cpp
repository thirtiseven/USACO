/*
ID: thirtis1
PROG: gift1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string> 
#define P_MAX 10

using namespace std;

string name1[P_MAX * 2];
string name2[P_MAX * 2];
int price[P_MAX * 2] = {0};
int money[P_MAX * 2] = {0};
int pgive[P_MAX * 2] = {0};

int main(int argc, char *argv[]){
	ofstream  fout ("gift1.out");  
	ifstream  fin  ("gift1.in");  
	int pamount;
	fin >> pamount;
	for(int h = 1;h <= pamount;h++){
		fin >> name1[h];
	}
	for(int i = 1;i <= pamount;i++){
		
		fin >> name2[i];
		int m;
		for (m = 1;m <= pamount;m++){
			if(name2[i] == name1[m]){
				break;
			}
		}
		fin >> money[m] >> pgive[m];
		price[m] -= money[m];
		if(money[m] != 0 && pgive[m] != 0){
			price[m] += money[m] % pgive[m];
		}
		
		for(int j = 1;j <= pgive[m];j++){
			string tempname;
			fin >> tempname;
			for(int q = 1;q <= pamount;q++){
				if(name1[q] == tempname){
					price[q] += money[m] / pgive[m];
					break;
				}
			}
		}
	}
	for(int i = 1;i <= pamount;i++){
		fout << name1[i] << ' ' << price [i] << '\n';
	}
	return 0;
}
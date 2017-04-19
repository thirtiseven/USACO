/*
ID: thirtis1
PROG: beads
LANG: C++11
*/

#include <iostream>
#include <fstream> 

using namespace std;

char necklace[360];
int main(int argc, char *argv[]) {
	ofstream  fout ("beads.out");  
	ifstream  fin  ("beads.in"); 
	int max = 0,length = 1,turn = 0,jack; 
	int num;
	fin >> num;
	for (int i = 1; i <= num; ++i){
		fin >> necklace[i];
	}
	char situation = necklace[1];
	for (int h = 2; h < num ; ++h){
		for (int j = h; j < num * 2; ++j)
		{
			jack = j;
			if(j > num){
				jack -= num;
			}
			if(necklace[jack] == situation){
				length++;
			}else if(necklace[jack] == 'w'){
				length++;
			}else if(necklace[jack] != situation){
				turn++;
				if(turn == 1){
					length++;
					situation = necklace[j];
				}else if(length > max){
					max = length;
					length = 0;
					turn = 0;
				}else{
					length = 0;
					turn = 0;
				}
			}
			if(length >= num){
				max = num;
			}
		}
	}
	fout << max << endl;
	return 0;
}
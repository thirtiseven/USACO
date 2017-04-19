/*
ID: thirtis1
PROG: milk2
LANG: C++11
*/


#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

typedef struct milkman{
	int begin;
	int end;
} farmer;

vector<farmer> moment;
vector<farmer> part;

int main(int argc, char *argv[]) {
	ofstream  fout ("milk2.out");  
	ifstream  fin  ("milk2.in"); 
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> moment[i].begin >> moment[i].end;
	}
	int length = 0 , max = 0 , j , h;
	for(j = 1;j < 2200;j++){
		for(h = 0;h < n;h++){
			if(j >= moment[h].begin && j <= moment[h].end){
				length++;
				break;
			}else{
				if(length > max){
					max = length;
				}
				length = 0;
			}
		}
	}
	return 0;
}
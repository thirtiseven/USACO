/*
ID: thirtis1
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;


int palsquare(int base , int n){
	int m = 0;
	char a[20];
	while (n != 0){
		a[m] = (char)(n%base+48);
		n = n / base;
		m++; 
	}
	for(int i = 0;i < m;i++){
		if(a[i] != a[m - 1 - i]){
			return -1;
		}
	}
	return 1;
}


int main(int argc, char *argv[]) {
	ofstream fout ("dualpal.out"); 
	ifstream fin ("dualpal.in");
	
	int n , s , state = 0;
	fin >> n >> s;
	for(int i = s+1;;i++){
		for(int j = 2;j <= 10;j++){
			if(palsquare(j, i) == 1){
				state += 1;
			}
		}
		if(state >= 2){
			fout << i <<endl;
			n--;
		}
		state = 0;
		if(n<=0){
			break;
		}
	}
	return 0;
}
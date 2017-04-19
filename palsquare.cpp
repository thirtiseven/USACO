/*
ID: thirtis1
PROG: palsquare
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

char a[20] , b[20];

int palsquare(int base , int n){
	int sum = 0 , m = 0;
	while (n != 0){
		a[m] = (char)(((n % base)>9?(n%base+55):(n%base+48)));
		n = n / base;
		m++; 
	}
	for(int i = 0;i < m;i++){
		if(a[i] != a[m - 1 - i]){
			return -1;
		}
	}
	return m;
}

int turn(int base , int n){
	int sum = 0 , m = 0;
	while (n != 0){
		b[m] = (char)(((n % base)>9?(n%base+55):(n%base+48)));
		n = n / base;
		m++; 
	}
	return m;
}

int main(int argc, char *argv[]) {
	ofstream fout ("palsquare.out"); 
	ifstream fin ("palsquare.in");
	int base,alice;
	fin >> base;
	for(int i = 1;i <= 300;i++){
		if(palsquare(base,i*i) != -1){
			alice = turn(base,i);
			for(int j = alice-1;j >= 0;j--){
				fout << b[j];
			}
			fout << ' ' << a << endl;
		}
	}
	return 0;
}
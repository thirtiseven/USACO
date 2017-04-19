/*
ID: thirtis1
PROG: ariprog
LANG: C++11 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

int bis[2*250*250+10];
int isinbis[2*250*250+10];

using namespace std;
int main(int argc, char *argv[]) {
	ofstream fout ("ariprog.out"); 
	ifstream fin ("ariprog.in");
	memset(isinbis,0,sizeof(isinbis));
	int n , m , temp;
	cin >> n >> m;
	int biscnt = -1;
	for(int i = 0;i <= m;i++){
		for(int j = 0;j <= m;j++){
			isinbis[i*i+j*j] = 1;
		}
	}
	for(int i = 0;i <= 2*m*m;i++){
		if(isinbis[i]){
			biscnt++;
			bis[biscnt] = i;
		}
	}
	int flag = 1;
	for(int b = 1;b <= 2*m*m/(n-1)+1;b++){
		for(int a = 0;bis[a] <= 2*m*m - (n-1) * b+1;a++){
			for(int i = 1;i < n;i++){
				if(!isinbis[bis[a] + b * i]){
					break;
				}
				if(i == n-1){
					cout << bis[a] << " " << b << endl;
					flag = 0;
				}
			}			
		}
	}
	if(flag){
		cout << "NONE" << endl;
	}
	return 0;
}
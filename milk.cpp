/*
ID: thirtis1
PROG: milk
LANG: C++11
*/

#include <iostream>
#include <fstream>


using namespace std;
int main(int argc, char *argv[]) {
	ofstream fout ("milk.out"); 
	ifstream fin ("milk.in");
	long long a[1010] = {0};
	long long N,M,temp,sum = 0,alice,bob;
	fin >> N >> M;
	for(int i = 0;i<M;i++){
		fin >> alice >> bob;
		a[alice] += bob;
		if(a[alice] > N){
			break;
		}
	}
	for(int i = 0;N>0;i++){
//		cout << sum << endl;
		if(a[i] != 0){
			if(a[i] <= N){
				sum += i * a[i];
				N -= a[i];
			}else{
				sum += i * N;
				N = 0;
				break;
			}
		}
	}
	fout << sum << endl;
	return 0;	
}
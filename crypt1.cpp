
/*
ID: thirtis1
PROG: crypt1
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int num[20] = {0};

int yes(int w){
	while(w>0){
		if(num[w%10]==0){
			return 0;
		}
		w /= 10;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	ofstream  fout ("crypt1.out");  
	ifstream  fin  ("crypt1.in");
	int numnum;
	int temp;
	fin >> numnum;
	for(int i = 0;i < numnum;i++){
		fin >> temp;
		num[temp]++;
	}
	int itis = 0;
	int firl,secl,res;
	for(int i = 100;i < 1000;i++){
		for(int j = 10;j < 100;j++){
			firl = i*(j/10);
			secl = i*(j%10);
			res = i*j;
			if(res > 10000||firl > 1000 || secl > 1000){
				continue;
			}
			if(yes(i)&&yes(j)&&yes(firl)&&yes(secl)&&yes(res)){
				itis++;
				cout << i << "*" << j << "=" << res << "0(. w .)0" << endl;
				continue;
			}
		}
	}
	fout << itis << endl;
	return 0;
}
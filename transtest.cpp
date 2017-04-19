/*
ID: thirtis1
PROG: transform
LANG: C++11
*/

#include <iostream> 
#include <fstream>

using namespace std;

char square1[15][15];
char square2[15][15];

int type6(int order){
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[i][j] ){
			return 0;
		}
	}
	return 6;
}

int type5(int order){
	int alice = 5 , bob = 5 , clare = 5;
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[order + 1 - j][order +1 - i]){
			alice = 0;
		}
	}
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[order +1 - i][j] ){
			bob = 0;	
		}
	}
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[j][i] ){
			clare = 0;
		}
	}
	return (alice == 0&&bob == 0&&clare == 0)?0:5;
}

int type4(int order){
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[i][order + 1 - j] ){
			return 0;
		}
	}
	return 4;
}

int type3(int order){
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[order + 1 - j][i] ){
			return 0;
		}
	}
	return 3;
}

int type2(int order){
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[order + 1 - i][order + 1 - j] ){
			return 0;
		}
	}
	return 2;
}

int type1(int order){
	for(int i = 1; i <= order ; i++) for(int j = 1; j <= order ; j++){
		if(square1[i][j] != square2[j][order + 1 - i]){
			return 0;
		}
	}
	return 1;
}

int type(int a){
	int back = 0;
	back = type1(a);
	if(back == 0){
		back = type1(a);
		cout << back << ' ';
	}
	if(back == 0){
		back = type2(a);
		cout << back << ' ';
	}
	if(back == 0){
		back = type3(a);
		cout << back << ' ';
	}
	if(back == 0){
		back = type4(a);
		cout << back << ' ';
	}
	if(back == 0){
		back = type5(a);
		cout << back << ' ';
	}
	if(back == 0){
		back = type6(a);
		cout << back << ' ';
	}
	if(back == 0){
		back = 7;
	}
	return back;
}

int main(int argc, char *argv[]) {
//	ofstream  fout ("transform.out");  
//	ifstream  fin  ("transform.in"); 
	int n;
	cin >> n;
	for(int i = 1; i <= n ; i++) for(int j = 1; j <= n ; j++){
		cin >> square1[i][j];
	}
	for(int i = 1; i <= n ; i++) for(int j = 1; j <= n ; j++){
		cin >> square2[i][j];
	}
	cout << type(n) << endl;
	return 0;
}
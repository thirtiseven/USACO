/*
ID: thirtis1
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

long long turn(char a[]){
	long long i = 0 , alice = 0 , n;
	while(a[i] != '\0'){
		if(a[i]>64 && a[i]<68){
			n = 2;
		}else if(a[i]<71){
			n = 3;
		}else if(a[i]<74){
			n = 4;
		}else if(a[i]<77){
			n = 5;
		}else if(a[i]<80){
			n = 6;
		}else if(a[i]<84){
			n = 7;
		}else if(a[i]<87){
			n = 8;
		}else{
			n = 9;
		}
		alice = alice * 10 + n;
		i++;
	}
	return alice;
}

int main(int argc, char *argv[]) {
	long long bob , j = 0;
	char a[15];
	cin >> bob;
	ifstream ifile;
	ifile.open("namenumdict.txt");
	while(1){
		ifile >> a;
		cout << turn(a) << ' ';
		if(bob == turn(a)){
			cout << a << endl;
		}
		if(ifile.eof()!=0){
			cout << "NONE" << endl;
			break;
		}
	}
	return 0;
}
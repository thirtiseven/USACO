/*
ID: thirtis1
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
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
	ofstream  fout ("namenum.out");  
	ifstream  fin  ("namenum.in");
	long long bob;
	int j,state = 0;
	char a[15];
	fin >> bob;
	ifstream ifile;
	ifile.open ("dict.txt");
	while(1){
		ifile >> a;
		if(bob == turn(a)){
			fout << a << endl;
			state = 1;
		}
		if(ifile.eof()!=0){
			if(state == 0){
				fout << "NONE" << endl;
			}	
 			break;
		 }
	}
	return 0;
}
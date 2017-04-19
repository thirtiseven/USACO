/*
ID: thirtis1
PROG: friday
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int isLeapYear(int alice){
	if(alice % 400 == 0){
		return 1;
	}else if(alice % 100 == 0){
		return 0;
	}else if(alice % 4 == 0){
		return 1;
	}else{
		return 0;
	}
}

int date13[10] = {0};
int addNum[15] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

int main(int argc, char const *argv[]){
	ofstream  fout ("friday.out");  
	ifstream  fin  ("friday.in");  
	int n;
	fin >> n;
	int year = n + 1899 , day = 13 , mouth = 1 , i = 1900;
	while (i <= year){
		date13[(day+1)%7]++;
		day += ((mouth == 2)?(addNum[mouth%12] + isLeapYear(i)):(addNum[mouth]));
		mouth++;
		if(mouth > 12){
			mouth = 1;
			i++;
		}
	}
	fout << date13[0];
	for (int j = 1; j < 7; ++j)
	{
		fout << ' ' << date13[j];
	}
	fout << endl;
	return 0;
}
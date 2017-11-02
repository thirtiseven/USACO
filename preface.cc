/*
ID: thirtis1
PROG: preface
LANG: C++11  
*/

#include <iostream>
#include <fstream>
#define maxn 3509

std::string division[4][10] = {{"","I","II","III","IV","V","VI","VII","VIII","IX"},
								{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
								{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
								{"","M","MM","MMM","","","","","",""}};		

std::string roman(int a) {
	std::string s;
	s += division[3][a/1000];
	s += division[2][(a%1000)/100];
	s += division[1][(a%100)/10];
	s += division[0][a%10];
	return s;
}

int main(int argc, char *argv[]) { 
	std::ofstream fout ("preface.out"); 
	std::ifstream fin ("preface.in"); 
	int num[7][maxn];
	char name[7] = {'I', 'V', 'X','L','C','D','M'};
	for(int i = 0; i < 7; i++) {
		num[i][0] = 0;
	}
	for(int i = 1; i <= 3500; i++) {
		for(int j = 0; j < 7; j++) {
			num[j][i] = num[j][i-1];
		}
		std::string t = roman(i);
		for(int j = 0; j < t.length(); j++) {
			switch(t[j]) {
				case 'I': {num[0][i]++;break;}
				case 'V': {num[1][i]++;break;}
				case 'X': {num[2][i]++;break;}
				case 'L': {num[3][i]++;break;}
				case 'C': {num[4][i]++;break;}
				case 'D': {num[5][i]++; break;}
				case 'M': {num[6][i]++; break;}
				default:;
			}
		}
	}
	int n;
	std::cin >> n;
	fin >> n;
	for(int i = 0; i < 7; i++) {
		if(num[i][n]) {
			std::cout << name[i] << " " << num[i][n] << "\n";
			fout << name[i] << " " << num[i][n] << "\n";
		}
	}
	return 0;
}
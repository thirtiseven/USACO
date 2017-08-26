/*
ID: thirtis1
PROG: numtri
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::ofstream  fout("numtri.out");  
	std::ifstream  fin("numtri.in");
	int n;
	int triangle[1005][1005], dp[1005][1005];
	//std::cin >> n;
	fin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			//std::cin >> triangle[i][j];
			fin >> triangle[i][j];
		}
	}
	for(int i = n - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			triangle[i][j] += std::max(triangle[i+1][j], triangle[i+1][j+1]);
		}
	}
	//std::cout << triangle[0][0] << std::endl;
	fout << triangle[0][0] << std::endl;
	return 0;
}
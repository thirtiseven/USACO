/*
ID: thirtis1
PROG: sort3
LANG: C++11 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) { 
	std::ofstream fout ("sort3.out"); 
	std::ifstream fin ("sort3.in"); 
	int n, a[1010];
	//std::cin >> n;
	fin >> n;
	int one = 0, two = 0;
	int t12 = 0, t23 = 0, t13 = 0, t21 = 0, t32 = 0, t31 = 0;
	for(int i = 0; i < n; i++) {
		//std::cin >> a[i];
		fin >> a[i];
		if(a[i] == 1) {
			one++;
		}
		if(a[i] == 2) {
			two++;
		}
	}
	for(int i = 0; i < one; i++) {
		if(a[i] == 2) {
			t21++;
		}
		if(a[i] == 3) {
			t31++;
		}
	}
	for(int i = one; i < one + two; i++) {
		if(a[i] == 1) {
			t12++;
		}
		if(a[i] == 3) {
			t32++;
		}
	}
	for(int i = one + two; i < n; i++) {
		if(a[i] == 2) {
			t23++;
		}
		if(a[i] == 1) {
			t13++;
		}
	}
	int d2, d3m2;
	d2 = std::min(t12, t21) + std::min(t13, t31) + std::min(t32, t23);
	d3m2 = abs(t12 - t21) + abs(t13 - t31) + abs(t32 - t23);
	int ans = d2 + d3m2 / 3 * 2;
	//std::cout << ans << '\n';
	fout << ans << '\n';
	return 0;
}
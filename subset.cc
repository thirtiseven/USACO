/*
ID: thirtis1
PROG: subset
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>

#define ll long long

int main(int argc, char *argv[]) { 
	std::ofstream fout ("subset.out"); 
	std::ifstream fin ("subset.in"); 
	ll n;
	std::cin >> n;
	fin >> n;
	if(n % 4 != 0 && n % 4 != 3) {
		std::cout << "0\n";
		fout << "0\n";
		return 0;
	}
	ll sum = (n + 1) * n / 4;
	ll dp[500];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = sum; j >= i; j--) {
			dp[j] = dp[j] + dp[j-i];
		}
	}
	std::cout << dp[sum]/2 << std::endl;
	fout << dp[sum]/2 << std::endl;
	return 0;
}
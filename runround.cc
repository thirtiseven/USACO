/*
ID: thirtis1
PROG: runround
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>

#define ll long long

bool is_runaround(ll a) {
	std::set<ll> num;
	std::vector<ll> dig;
	while(a) {
		ll temp = a%10;
		if(!temp) {
			return false;
		}
		num.insert(temp);
		dig.push_back(temp);
		a /= 10;
	}
	reverse(dig.begin(), dig.end());
	ll len = dig.size();
	if(len != num.size()) {
		return false;
	}
	num.clear();
	ll pos = 0;
	for(int i = 0; i < len; i++) {
		ll a = dig[pos];
		pos = (pos + a) % len;
		num.insert(dig[pos]);
		//std::cout << dig[pos];
	}
	if(num.size() == len) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) { 
	std::ofstream fout ("runround.out"); 
	std::ifstream fin ("runround.in"); 
	ll m;
	std::cin >> m;
	fin >> m;
	do {
		m++;
	}while(!is_runaround(m));
	std::cout << m << std::endl;
	fout << m << std::endl;
	return 0;
}
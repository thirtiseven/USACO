/*
ID: thirtis1
PROG: holstein
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>

#define inf 0x7f7f7f7f

int v, vita[1000], need[40][1000], g;
int now[1000], id[1000], p = inf, ans[1000];

bool check() {
	for(int i = 0; i < v; i++) {
		if(now[i] < vita[i]) {
			return false;
		}
	}
	return true;
}

void violence(int alice, int bob) {
	id[alice - 1] = bob;
	if(check() && alice < p) {
		p = alice;
		for(int i = 0; i < p; i++)
			ans[i] = id[i];
	}
	for(int i = bob + 1; i < g; i++) {
		for(int j = 0; j < v; j++) {
			now[j] += need[i][j];
		}
		violence(alice + 1, i);
		for(int j = 0; j < v; j++) {
			now[j] -= need[i][j];
		}
	}
}

int main(int argc, char *argv[]) { 
	std::ofstream fout ("holstein.out"); 
	std::ifstream fin ("holstein.in"); 
	std::cin >> v;
	fin >> v;
	for(int i = 0; i < v; i++) {
		std::cin >> vita[i];
		fin >> vita[i];
	}
	std::cin >> g;
	fin >> g;
	for(int j = 0; j < g; j++) {
		for(int i = 0; i < v; i++) {
			std::cin >> need[j][i];
			fin >> need[j][i];
		}
	}
	for(int j = 0; j < g; j++) {
		for(int i = 0; i < v; i++) {
			now[i] = need[j][i];
		}
		violence(1, j);
		for(int i = 0; i < v; i++) {
			now[i] -= need[j][i];
		}
	}
	std::cout << p;
	fout << p;
	for(int i = 0; i < p; i++) {
		std::cout << " " << ans[i]+1;
		fout << " " << ans[i]+1;
	}
		std::cout << '\n';
	fout << '\n';
	return 0;
}
/*
ID: thirtis1
PROG: prefix
LANG: C++11  
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>

const int maxn = 2000 + 10; 
const int max_stringlen = 26 + 2;
int trie[maxn][max_stringlen];
bool val[maxn];
int trie_index;
std::string s;
bool dp[200007];

int index_of(const char &c) { 
	return (c - 'A');
}

void trie_init() { 
	trie_index = 0;
	memset(val, 0, sizeof(val));
	memset(trie, 0, sizeof(trie)); 
	memset(dp, 0, sizeof(dp));
}

void trie_insert(const std::string s) { 
	int len = s.length();
	int now = 0;
	for (int i = 0; i < len; ++i) {
		int idx = index_of(s[i]); 
		int &tr = trie[now][idx]; 
		if (!tr) {
			tr = ++trie_index; 
		}
		now = tr; 
	}
	val[now] = true; 
}

bool trie_search(int l, int r) {
	int now = 0;
	for(int i = l; i <= r; i++) {
		if(!trie[now][index_of(s[i])]) {
			return false;
		}
		now = trie[now][index_of(s[i])];
	}
	return val[now];
}

int main(int argc, char *argv[]) { 
	std::ofstream fout ("prefix.out"); 
	std::ifstream fin ("prefix.in"); 
	std::string temp;
	trie_init();
	while(fin >> temp) {
		if(temp == ".") {
			break;
		}
		trie_insert(temp);
	}
	s = "x";
	while(fin >> temp) {
		s += temp;
	}
	int n = s.length() - 1;
	std::cout << n << std::endl;
	int ans = 0;
	dp[0] = true;
	for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j >= 0 && i - j <= 10; j--) {
			if(!dp[j]) {
				continue;
			}
			if(trie_search(j+1, i)) {
				dp[i] = true;
				ans = std::max(i, ans);
				break;
			}
		}
	}
	std::cout << ans << std::endl;
	fout << ans << std::endl;
	return 0;
}
/*
ID: thirtis1
PROG: hamming
LANG: C++11 
*/

#include <iostream>
#include <fstream>

#define ll int
#define maxn 70

ll tot = 1, ans[maxn];
ll n, b, d;

bool check(ll alice, ll bob) {
	ll cnt = 0;
	for(int i = 1; i <= b; i++) {
		if(((alice >> (i-1)) & 1) != ((bob >> (i-1)) & 1)) {
			cnt++;
		}
	}
	if(cnt >= d) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) { 
	std::ofstream fout ("hamming.out"); 
	std::ifstream fin ("hamming.in"); 
	std::cin >> n >> b >> d;
	fin >> n >> b >> d;
	ans[0] = 0;
	bool flag;
	for(ll i = 1; i <= ((1 << b) - 1); i++) {
		if(tot > n) {
			break;
		}
		flag = true;
		for(int j = 0; j < tot; j++) {
			if(!check(ans[j], i)) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			continue;
		} else {
			ans[tot] = i;
			tot++;
		}
	}
	for(ll i = 0; i < n-1; i++) {
		std::cout << ans[i] << (((i+1)%10==0)?"\n":" ");
		fout << ans[i] << (((i+1)%10==0)?"\n":" ");
	}
	std::cout << ans[n-1] << std::endl;
	fout << ans[n-1] << std::endl;
	return 0;
}
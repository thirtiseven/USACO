/*
ID: thirtis1
PROG: frac1
LANG: C++11 
*/

#include <iostream>
#include <fstream>
#include <set>

struct fraction {
	int up, down;
	double val;
	fraction(void) { }
	fraction(int a, int b) {
		up = a, down = b;
		val = double(a) / double(b);
	}
	bool operator < (const fraction  &b) const {
		return (this -> val < b.val);
	}
};

int gcd(int a, int b) { 
	int t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

std::set<fraction> ans;

int main(int argc, char *argv[]) { 
	std::ofstream fout ("frac1.out"); 
	std::ifstream fin ("frac1.in"); 
	int n;
	//std::cin >> n;
	fin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(gcd(i, j) == 1) {
				ans.insert(fraction(j, i));
			}
		}
	}
	//std::cout << "0/1\n";
	fout << "0/1\n";
	for(std::set<fraction>::iterator it = ans.begin(); it != ans.end(); it++) {
		//std::cout << (*it).up << "/" << (*it).down << '\n';
		fout << (*it).up << "/" << (*it).down << '\n';
	}
	return 0;
}
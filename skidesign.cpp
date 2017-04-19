/*
ID: thirtis1
PROG: skidesign
LANG: C++11 
*/

#include <iostream>
#include <fstream>

#define INF 0x3fffffff

using namespace std;
int main(int argc, char *argv[]) {
	ofstream fout ("skidesign.out"); 
	ifstream fin ("skidesign.in");
	int n;
	fin >> n;
	int mou[1020];
	for(int i = 0;i < n;i++){
		fin >> mou[i];
	}
	int minspend = INF;
	int spend = 0;
	for(int hillfirst = 1;hillfirst + 17 <= 100 ; hillfirst++){
		for(int i = 0;i < n;i++){
			if(mou[i] > hillfirst + 17){
				spend += (mou[i] - hillfirst - 17) * (mou[i] - hillfirst - 17);
			}else if(mou[i] < hillfirst){
				spend += (hillfirst - mou[i])*(hillfirst - mou[i]);
			}else{
				continue;
			}
		}
		if(spend < minspend){
			minspend = spend;
			spend = 0;
		}
	}
	fout << minspend << endl;
	return 0;
}
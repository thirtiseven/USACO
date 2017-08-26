/*
ID: thirtis1
PROG: castle
LANG: C++11
*/

#include <fstream> 
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 100

bool vis[maxn][maxn];
int colour;
int m, n;
int castle[maxn][maxn];
int roomid[maxn][maxn];
int roomsize[maxn * maxn];

void floodfill(int l, int c, int id) {
	if(vis[l][c] || l < 0 || l >= n || c < 0 || c >= m) {
		return;
	}
	vis[l][c] = 1;
	roomid[l][c] = id;
	roomsize[id]++;
	int tmp = castle[l][c] ^ ((1 << 10) - 1);
	if (tmp & 8) {
		floodfill(l+1, c, id);
	}
	if (tmp & 4) {
		floodfill(l, c+1, id);
	}
	if (tmp & 2) {
		floodfill(l-1, c, id);
	}
	if (tmp & 1) {
		floodfill(l, c-1, id);
	}
}

int main(int argc, char *argv[]) {  
	std::ofstream  fout("castle.out");  
	std::ifstream  fin("castle.in");
	//std::cin >> m >> n;
	fin >> m >> n; 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			//std::cin >> castle[i][j];
			fin >> castle[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));
	memset(roomsize, 0, sizeof(roomsize));
	colour = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!vis[i][j]) {
				colour++;
				//std::cout << colour << " " << castle[i][j] << "\n";
				floodfill(i, j, colour);
			}
		}
	}
	int maxsize = -1;
	for(int i = 0; i <= colour; i++) {
		maxsize = std::max(roomsize[i], maxsize);
	}
	//std::cout << colour << "\n" << maxsize << "\n";
	fout << colour << "\n" << maxsize << "\n";
	int sum_of_two = -1;
	int ansx = 0, ansy = 0;
	char ansd = 'O';
	for(int j = 0; j < m; j++) {
		for(int i = n-1; i >= 0; i--) {
			if(i > 0) {
				if(roomid[i][j] != roomid[i-1][j]) {
					if(roomsize[roomid[i][j]] + roomsize[roomid[i-1][j]] > sum_of_two) {
						sum_of_two = roomsize[roomid[i][j]] + roomsize[roomid[i-1][j]];
						ansx = i+1, ansy = j+1, ansd = 'N';
					}
				}
			}
			if(j < m - 1) {
				if(roomid[i][j] != roomid[i][j+1]) {
					if(roomsize[roomid[i][j]] + roomsize[roomid[i][j+1]] > sum_of_two) {
						sum_of_two = roomsize[roomid[i][j]] + roomsize[roomid[i][j+1]];
						ansx = i+1, ansy = j+1, ansd = 'E';
					}
				}
			}
		}
	}
	//std::cout << sum_of_two << "\n" << ansx << " " << ansy << " " << ansd << "\n";
	fout << sum_of_two << "\n" << ansx << " " << ansy << " " << ansd << "\n";
	return 0;
}
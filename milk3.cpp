/*
ID: thirtis1 
PROG: milk3
LANG: C++11  
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int vis[30][30];
int a,b,c;

void dfs(int x,int y,int z){
	if(vis[x][z]){
		return;
	}
	vis[x][z] = 1;
	dfs(min(a,x+z),y,max(z+x-a,0));
	dfs(x,min(b,y+z),max(z+y-b,0));
	dfs(max(x+y-b,0),min(b,x+y),z);
	dfs(max(x+z-c,0),y,min(c,x+z));
	dfs(min(a,x+y),max(x+y-a,0),z);
	dfs(x,max(y+z-c,0),min(c,y+z));
}

int main(int argc, char *argv[]) {
	ofstream fout ("milk3.out"); 
	ifstream fin ("milk3.in"); 
	memset(vis,0,sizeof(vis));
	fin >> a >> b >> c;	
	dfs(0,0,c);
	int flag = 0;
	for(int i = 0;i <= c;i++){
		if(vis[0][i]){
			if(flag){
				fout << " ";
			}
			fout << i;
			flag = 1;
		}
	}
	fout << endl;
	return 0;
}
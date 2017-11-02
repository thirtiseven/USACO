/*
ID: thirtis1
PROG: lamps
LANG: C++11 
*/

#include <fstream>
using namespace std;
ifstream   cin("lamps.in");
ofstream   cout("lamps.out");
int light[10][10]= {{0,0,0,0,0,0,0},
					{0,0,0,1,1,1,0},
					{0,0,1,0,1,0,1},
					{0,0,1,1,0,1,1},
					{0,1,0,0,1,0,0},
					{0,1,0,1,0,1,0},
					{0,1,1,0,0,0,1},
					{0,1,1,1,1,1,1}};
int flag=1,N,C,reqstate[7]={-1};
void check(int x)
{
	for(int i=1;i<7;i++)if(reqstate[i]!=-1&&reqstate[i]!=light[x][i])return;
	flag=0;
	for(int i=0;i<N;i++)cout<<light[x][1+i%6];
	cout<<endl;
}
 int main()
{
	for(int i=0;i<7;++i)reqstate[i]=-1;
	cin>>N>>C;
	for(int i=1,tmp=0;i>=0;--i)while(cin>>tmp&&tmp!=-1)reqstate[1+(tmp-1)%6]=i;
	switch(C)
	{
		case 0:{check(7);break;}
		case 1:{check(0);check(2);check(3);check(5);break;}
		case 2:{for(int i=0;i<8;i++)if(i!=3)check(i);break;}
		default:{for(int i=0;i<8;i++)check(i);break;}
	}
	if(flag)cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

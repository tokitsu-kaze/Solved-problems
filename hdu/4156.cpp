////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 23:31:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4156
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1568KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int a[5];
	while(~scanf("%d%d%d",&a[0],&a[1],&a[2])&&(a[0]+a[1]+a[2]))
	{
		sort(a,a+3);
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) puts("right");
		else puts("wrong");
	}
	return 0;
}
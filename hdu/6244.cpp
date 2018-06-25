////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-08 18:18:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6244
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int ans[200][9]={
1,2,2,2,2,2,2,2,2
,2,1,2,1,3,3,3,2,2
,3,3,1,3,4,4,4,3,1
,4,2,3,1,3,4,4,2,3
,4,4,3,3,1,3,4,4,3
,3,3,1,2,3,1,3,3,1
,4,5,3,3,4,3,1,3,3
,5,3,3,2,4,4,3,1,3
,4,4,2,4,4,5,4,3,1
,3,4,4,3,2,4,4,3,3
,2,3,3,3,3,3,3,3,3
,3,3,2,2,3,2,4,3,2
,4,4,4,3,4,4,4,5,4
,5,4,4,3,4,4,2,4,4
,6,5,3,4,3,5,4,4,2
,6,3,4,2,4,5,5,2,4
,5,5,4,4,4,4,5,4,4
,6,4,2,3,4,3,4,4,2
,6,5,4,4,3,4,5,4,4
,5,3,3,2,3,3,5,4,3
,5,4,3,4,5,4,3,5,3
,4,2,4,2,4,5,5,4,4
,5,4,4,3,3,5,6,4,4
,4,2,3,1,2,4,4,2,3
,5,4,4,3,2,5,5,4,4
,6,3,4,2,4,4,6,4,4
,6,5,2,4,5,4,5,5,2
,7,4,4,2,4,5,4,4,4
,7,6,4,4,3,4,6,6,4
,6,5,3,3,3,3,6,5,3
,6,5,4,4,4,5,5,5,4
,5,4,4,3,4,5,6,3,4
,5,5,2,4,5,5,6,5,3
,6,5,4,4,4,5,6,5,4
,6,5,4,4,4,4,4,5,4
,5,4,2,3,5,2,6,4,2
,6,6,4,4,5,4,6,5,4
,7,5,4,4,5,5,5,6,4
,7,6,3,5,5,5,6,6,3
,7,4,3,3,5,4,5,4,3
,8,6,4,4,5,5,5,5,4
,7,4,3,3,5,3,3,6,3
,7,5,4,4,4,5,5,6,4
,6,3,5,2,5,6,6,4,4
,7,5,4,4,4,6,6,5,3
,7,4,4,3,5,5,6,6,4
,7,5,5,4,4,5,5,5,4
,6,3,4,2,3,4,4,4,3
,6,5,5,4,4,5,2,4,4
,7,4,5,3,3,5,4,5,4
,8,6,4,4,5,6,5,6,3
,8,4,5,3,5,6,6,5,4
,7,6,5,5,4,5,5,5,4
,7,5,3,4,4,4,6,5,2
,6,5,5,5,2,5,5,5,4
,6,5,4,3,4,5,3,3,3
,7,6,4,5,5,5,5,5,3
,8,6,4,4,5,5,6,5,4
,7,6,5,5,5,5,6,6,4
,6,5,3,3,3,3,4,4,3
,7,6,4,5,5,5,6,5,4
,7,4,5,3,6,6,6,4,4
,6,5,4,4,6,5,4,4,3
,5,3,3,2,5,4,4,2,3
,6,5,5,4,3,4,5,4,4
,5,4,3,3,5,2,5,4,3
,6,6,4,5,5,4,5,5,4
,7,5,5,3,6,5,6,4,4
,7,7,4,5,6,6,5,5,4
,6,5,4,4,4,5,3,4,4
,5,6,4,5,5,5,3,3,3
,6,5,3,3,4,3,4,3,3
,7,6,4,5,5,5,6,5,4
,7,6,4,4,5,6,6,5,3
,7,6,4,5,4,6,5,5,3
,7,6,5,4,6,6,4,5,4
,6,6,4,5,5,5,2,5,3
,7,6,4,4,5,4,4,5,3
,8,6,4,5,4,6,5,4,3
,7,5,3,3,4,5,5,3,2
,6,5,3,4,6,6,6,4,2
,7,6,4,4,6,6,6,5,4
,8,6,4,5,6,5,5,6,3
,7,5,4,4,5,4,3,4,3
,8,7,5,5,5,5,5,5,4
,8,5,4,4,5,5,6,4,3
,7,6,4,5,5,6,6,4,3
,7,4,5,3,5,6,5,2,4
,6,6,5,5,5,5,5,4,3
,7,5,4,4,4,5,4,4,3
,8,7,5,5,4,6,4,5,4
,8,5,5,3,5,6,6,4,4
,8,6,4,4,6,6,7,6,3
,8,5,5,3,5,5,7,5,5
,9,6,5,4,3,5,6,5,4
,8,4,4,2,3,4,5,3,3
,8,6,5,4,4,5,5,5,4
,7,5,5,3,5,6,3,5,4
,6,6,3,4,6,5,5,5,2
,5,5,4,3,4,4,6,4,4
,6,6,5,5,4,5,6,6,4
,7,6,4,4,5,4,5,6,3
,8,7,5,5,5,5,4,5,5
,7,5,5,3,5,6,5,4,4
,6,7,4,5,4,5,4,5,3
,7,6,5,4,5,5,6,6,5
,7,6,5,5,5,5,7,6,4
,6,6,3,4,4,4,7,5,3
,5,5,5,5,4,4,6,5,5
,4,5,5,4,3,5,5,5,4
,3,4,4,4,4,4,4,4,3
,4,5,5,3,5,5,5,4,4
,5,5,4,5,5,4,5,5,4
,6,6,3,4,4,3,6,6,3
,7,6,4,5,2,4,7,6,4
,7,6,4,4,4,5,7,6,4
,6,6,3,5,5,5,6,6,3
,6,5,4,4,4,4,5,5,4
,5,5,3,5,3,3,5,5,3
,4,4,2,3,1,2,4,4,2
,4,4,3,4,3,3,5,4,3
,5,5,4,4,4,4,6,6,4
,6,5,3,5,5,5,7,6,3
,7,5,4,4,4,5,6,5,4
,7,6,4,4,2,4,6,6,4
,7,5,3,4,4,3,4,5,3
,7,6,4,4,5,4,5,5,4
,6,4,5,3,5,5,4,3,4
,7,6,4,4,5,6,6,5,3
,7,5,5,4,3,5,7,5,4
,6,7,5,5,4,4,5,6,5
,5,5,4,4,4,4,6,5,4
,6,6,5,5,5,5,5,7,5
,7,6,5,5,5,5,6,5,4
,7,6,5,5,4,6,5,5,3
,8,6,5,4,5,6,7,4,4
,9,7,5,5,5,5,6,6,5
,8,6,4,4,5,5,6,6,4
,8,7,5,5,4,5,6,6,5
,8,6,4,4,4,4,5,5,4
,8,7,5,5,6,5,6,6,4
,7,5,5,4,5,6,5,4,5
,6,6,5,4,4,6,7,6,5
,5,4,4,3,3,4,5,4,4
,6,6,6,4,3,6,7,6,5
,7,5,5,4,5,5,6,6,5
,8,7,4,5,6,6,4,6,4
,8,6,5,4,5,6,5,6,5
,9,8,6,5,4,6,6,7,5
,8,6,5,4,4,4,7,5,5
,9,8,6,5,5,6,6,6,4
,9,6,5,4,5,6,6,4,5
,8,8,4,5,6,6,6,6,4
,7,7,5,5,5,5,4,6,4
,7,7,5,5,4,5,6,7,5
,6,6,4,4,6,4,7,6,4
,7,8,5,5,6,5,7,6,4
,8,6,5,5,6,6,7,6,5
,9,7,4,6,5,6,7,5,4
,8,6,4,4,4,5,6,5,3
,9,7,5,6,5,5,5,6,4
,8,5,3,4,6,5,7,5,3
,9,7,5,5,5,6,6,6,4
,9,6,5,5,6,7,6,6,5
,8,7,4,5,5,6,6,6,4
,9,6,5,5,6,6,7,6,4
,8,6,5,5,5,6,6,6,4
,7,6,4,4,4,5,5,5,3
,6,5,5,4,5,6,6,6,4
,7,7,5,5,4,6,7,6,4
,8,6,5,5,6,7,5,5,4
,9,6,6,4,6,7,5,6,5
,10,7,6,5,5,6,6,7,5
,9,6,5,4,5,5,6,6,4
,8,7,6,5,3,6,5,6,5
,8,5,5,3,5,6,6,4,5
,8,7,5,5,6,6,6,6,4
,8,6,5,4,6,7,6,6,5
,8,6,6,4,6,6,6,6,4
,7,5,4,3,4,4,5,5,4
,8,6,6,4,6,6,5,6,5
,8,6,6,4,7,6,6,6,5
,9,7,4,5,7,7,7,6,5
,9,6,5,4,6,6,7,4,5
,8,7,6,5,4,5,7,6,5
,8,7,5,4,6,4,7,6,4
,7,7,6,5,6,5,6,6,5
,8,6,6,4,7,6,6,5,5
,9,7,4,5,7,6,5,5,4
,9,6,6,4,5,6,7,5,5
,9,7,5,5,6,6,6,5,5
,8,5,4,3,5,5,7,3,4
,9,7,5,5,6,6,7,5,5
,9,6,5,4,6,7,7,5,5
,8,7,4,5,5,6,6,5,5
,7,5,5,4,7,5,4,5,5
,8,7,5,5,6,6,6,6,5
,8,5,3,5,6,5,7,6,4
,8,6,5,5,5,6,6,6,4
,7,5,4,4,5,6,8,4,4};
//https://mathsfans.github.io/Tchisla/
int main()
{
	int t,d,n,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&d,&n);
		printf("Case #%d: %d\n",cas++,ans[n-1][d-1]);
	}
	return 0;
}
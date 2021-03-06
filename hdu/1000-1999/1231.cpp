////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-06 17:04:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
int v[MAX];
int main()
{
	int n,i,ans,l,r,now,nowl;
	while(~scanf("%d",&n)&&n)
	{
		now=0;
		ans=-1;
		nowl=l=1;
		r=n;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			now+=v[i];
			if(now>ans)
			{
				ans=now;
				l=nowl;
				r=i;
			}
			if(now<0)
			{
				now=0;
				nowl=i+1;
			}
		}
		printf("%d %d %d\n",max(0,ans),v[l],v[r]);
	}
	return 0;
}